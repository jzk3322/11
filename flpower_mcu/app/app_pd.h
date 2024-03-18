
#ifndef APP_PD_H
#define APP_PD_H


#include "PD_UFP_Protocol.h"
#include "app_pd_log.h"

#define PD_POLLING              100
#define TYPEC_SINK_WAIT_CAP     350
#define REQUEST_TO_PS_READY     580
#define PPS_REQUEST             5000

typedef uint8_t status_power_t;

enum {
    STATUS_LOG_MSG_TX,
    STATUS_LOG_MSG_RX,
    STATUS_LOG_DEV,
    STATUS_LOG_CC,
    STATUS_LOG_SRC_CAP,
    STATUS_LOG_POWER_READY,
    STATUS_LOG_POWER_PPS_STARTUP,
    STATUS_LOG_POWER_REJECT,
    STATUS_LOG_LOAD_SW_ON,
    STATUS_LOG_LOAD_SW_OFF,
};

enum {
    STATUS_POWER_NA = 0,
    STATUS_POWER_TYP,
    STATUS_POWER_PPS
};

typedef enum
{
    kPD_idle = 0x01,
    kPD_start, 
    kPD_START_2, 
    kPD_ON,
    kPD_SET,
    kPD_PPS_START_1, 
    kPD_PPS_START_2,
    kPD_PPS_ON,
    kPD_PPS_SET,
    kPD_FAIL,
    kPD_RST,
    kPD_CHECK, // PD 检测
} App_PD_state_t;

typedef struct
{
    App_PD_state_t state;
    uint8_t pd_ic_initial;
    PD_protocol_t protocol;
    
    // Power ready power
    uint16_t ready_voltage;
    uint16_t ready_current;
    
    // PPS setup
    uint16_t PPS_voltage_next;
    uint8_t PPS_current_next;
    // Status
    uint8_t status_initialized;
    uint8_t status_src_cap_received;
    status_power_t status_power;
    // Timer and counter for PD Policy
    uint32_t time_polling;
    uint32_t time_wait_src_cap;
    uint32_t time_wait_ps_rdy;
    uint32_t time_PPS_request;
    uint8_t get_src_cap_retry_count;
    uint8_t wait_src_cap;
    uint8_t wait_ps_rdy;
    uint8_t send_request;
}App_PD_t;

extern App_PD_t app_pt;

#endif
