
#include "app_includes.h"

#define delay_ms    HalDelayMs
#define clock_ms    xTaskGetTickCount

App_PD_t app_pt;

void status_power_ready(status_power_t status, uint16_t voltage, uint16_t current)
{
    app_pt.ready_voltage = voltage;
    app_pt.ready_current = current;
    app_pt.status_power = status;
    xEventGroupSetBits(xSysEvent, xSysEvent_PowerReady);
}

void set_default_power(void)
{
    status_power_ready(STATUS_POWER_TYP, PD_V(5), PD_A(1));
    status_log_event(STATUS_LOG_POWER_READY, 0);
}

void handle_protocol_event(PD_protocol_event_t events)
{    
    if (events & PD_PROTOCOL_EVENT_SRC_CAP) {
        app_pt.wait_src_cap = 0;
        app_pt.get_src_cap_retry_count = 0;
        app_pt.wait_ps_rdy = 1;
        app_pt.time_wait_ps_rdy = clock_ms();
        status_log_event(STATUS_LOG_SRC_CAP, 0);
    }
    if (events & PD_PROTOCOL_EVENT_REJECT) {
        if (app_pt.wait_ps_rdy) {
            app_pt.wait_ps_rdy = 0;
            status_log_event(STATUS_LOG_POWER_REJECT,0);
        }
    }    
    if (events & PD_PROTOCOL_EVENT_PS_RDY) {
        PD_power_info_t p;
        uint8_t i, selected_power = PD_protocol_get_selected_power(&app_pt.protocol);
        PD_protocol_get_power_info(&app_pt.protocol, selected_power, &p);
        app_pt.wait_ps_rdy = 0;
        if (p.type == PD_PDO_TYPE_AUGMENTED_PDO) {
            // PPS mode
            FUSB302_set_vbus_sense(&board.fusb302, 0);
            if (app_pt.PPS_voltage_next) {
                // Two stage startup for PPS voltage < 5V
                PD_protocol_set_PPS(&app_pt.protocol, app_pt.PPS_voltage_next, app_pt.PPS_current_next, false);
                app_pt.PPS_voltage_next = 0;
                app_pt.send_request = 1;
                status_log_event(STATUS_LOG_POWER_PPS_STARTUP, 0);
            } else {
                app_pt.time_PPS_request = clock_ms();
                status_power_ready(STATUS_POWER_PPS, 
                    PD_protocol_get_PPS_voltage(&app_pt.protocol), PD_protocol_get_PPS_current(&app_pt.protocol));
                status_log_event(STATUS_LOG_POWER_READY,0);
            }
        } else {
            FUSB302_set_vbus_sense(&board.fusb302, 1);
            status_power_ready(STATUS_POWER_TYP, p.max_v, p.max_i);
            status_log_event(STATUS_LOG_POWER_READY,0);
        }
    }
}

void handle_FUSB302_event(FUSB302_event_t events)
{
    if (events & FUSB302_EVENT_DETACHED) {
        PD_protocol_reset(&app_pt.protocol);
        return;
    }
    if (events & FUSB302_EVENT_ATTACHED) {
        uint8_t cc1 = 0, cc2 = 0, cc = 0;
        FUSB302_get_cc(&board.fusb302, &cc1, &cc2);
        PD_protocol_reset(&app_pt.protocol);
        if (cc1 && cc2 == 0) {
            cc = cc1;
        } else if (cc2 && cc1 == 0) {
            cc = cc2;
        }
        /* TODO: handle no cc detected error */
        if (cc > 1) {
            app_pt.wait_src_cap = 1;
        } else {
            set_default_power();
        }
        status_log_event(STATUS_LOG_CC,0);
    }
    if (events & FUSB302_EVENT_RX_SOP) {
        PD_protocol_event_t protocol_event = 0;
        uint16_t header;
        uint32_t obj[7];
        FUSB302_get_message(&board.fusb302, &header, obj);
        PD_protocol_handle_msg(&app_pt.protocol, header, obj, &protocol_event);
        status_log_event(STATUS_LOG_MSG_RX, obj);
        if (protocol_event) {
            handle_protocol_event(protocol_event);
        }
    }
    if (events & FUSB302_EVENT_GOOD_CRC_SENT) {
        uint16_t header;
        uint32_t obj[7];
        delay_ms(2);  /* Delay respond in case there are retry messages */
        if (PD_protocol_respond(&app_pt.protocol, &header, obj)) {
            status_log_event(STATUS_LOG_MSG_TX, obj);
            FUSB302_tx_sop(&board.fusb302, header, obj);
        }
    }
}

bool timer(void)
{
    uint32_t t = clock_ms();
    if (app_pt.wait_src_cap && t - app_pt.time_wait_src_cap > TYPEC_SINK_WAIT_CAP) {
        app_pt.time_wait_src_cap = t;
        if (app_pt.get_src_cap_retry_count < 3) {
            uint16_t header;
            app_pt.get_src_cap_retry_count += 1;
            /* Try to request soruce capabilities message (will not cause power cycle VBUS) */
            PD_protocol_create_get_src_cap(&app_pt.protocol, &header);
            status_log_event(STATUS_LOG_MSG_TX,0);
            FUSB302_tx_sop(&board.fusb302, header, 0);
        } else {
            app_pt.get_src_cap_retry_count = 0;
            /* Hard reset will cause the source power cycle VBUS. */
            FUSB302_tx_hard_reset(&board.fusb302);
            PD_protocol_reset(&app_pt.protocol);
        }
    }
    if (app_pt.wait_ps_rdy) {
        if (t - app_pt.time_wait_ps_rdy > REQUEST_TO_PS_READY) {
            app_pt.wait_ps_rdy = 0;
            set_default_power();
        }
    } else if (app_pt.send_request || (app_pt.status_power == STATUS_POWER_PPS && t - app_pt.time_PPS_request > PPS_REQUEST)) {
        app_pt.wait_ps_rdy = 1;
        app_pt.send_request = 0;
        app_pt.time_PPS_request = t;
        uint16_t header;
        uint32_t obj[7];
        /* Send request if option updated or regularly in PPS mode to keep power alive */
        PD_protocol_create_request(&app_pt.protocol, &header, obj);
        status_log_event(STATUS_LOG_MSG_TX, obj);
        app_pt.time_wait_ps_rdy = clock_ms();
        FUSB302_tx_sop(&board.fusb302, header, obj);
    }
    if (t - app_pt.time_polling > PD_POLLING) {
        app_pt.time_polling = t;
        return true;
    }
    return false;
}

void task_pd(void *para)
{
    uint8_t i;
    FUSB302_event_t FUSB302_events = 0;
    if(FUSB302_init(&board.fusb302)!=FUSB302_SUCCESS)
    {
        //发送初始化失败
        app_pt.pd_ic_initial = 0;
        //vTaskDelete(NULL);
    }
    else
        app_pt.status_initialized = 1;
    PD_protocol_init(&app_pt.protocol);
    PD_protocol_set_power_option(&app_pt.protocol, PD_POWER_OPTION_MAX_POWER);
    PD_protocol_set_PPS(&app_pt.protocol, 0, 0, false);
    status_log_event(STATUS_LOG_DEV,0);
    while(1)
    {
        if(GpioGetValue(&board.fusb302_int_gpio_handle)==0)
        {
            i = 0;
        }
        if(timer() || GpioGetValue(&board.fusb302_int_gpio_handle)==0)
        {
            FUSB302_events = 0;
            for(i=0;i<3 && FUSB302_alert(&board.fusb302, &FUSB302_events) != FUSB302_SUCCESS; i++){}
            if(FUSB302_events)
            {
                handle_FUSB302_event(FUSB302_events);
            }
        }
        vTaskDelay(10);
    }
}
