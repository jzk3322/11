#include "app_includes.h"

/*---------------------------------------------------------------
 * 电源输出界面
 * gui_sp_set_refresh(), 刷新电压电流设置等信息
 * gui_sp_power_select_refresh(), 刷新电源输入选择信息
*/
void gui_sp_set_refresh(void)
{
    char str[16];
    uint_to_str(str, device.para.run.load_v_set/10, 2, 6, "V");
    lv_label_set_text(ui_SP_LabelSetV, str);
    uint_to_str(str, device.para.run.load_i_set/10, 2, 6, "A");
    lv_label_set_text(ui_SP_LabelSetI, str);
}

void gui_sp_power_select_refresh(void)
{
    char str[16];
    uint_to_str(str, app_pt.ready_voltage/20, 0, 3, "V");
    uint_to_str(str+strlen(str), app_pt.ready_current/10, 1, 4, "A");
    lv_label_set_text(ui_SP_LabelPSelect, str);
}

void gui_sp_timerRefresh(lv_timer_t *timer)
{
    char str[16];
    volatile float value;
	
    value = device.meter.loadCurrent.value>0?device.meter.loadCurrent.value:0;
    float_to_str(str, value, 3, 6, "A");
    lv_label_set_text(ui_SP_LabelLoadI, str);
    float_to_str(str, device.meter.loadVoltage.value, 2, 6, "V");
    lv_label_set_text(ui_SP_LabelLoadV, str);
	
		value = device.meter.loadPower.value>0?device.meter.loadPower.value:0;
    float_to_str(str, value, 2, 6, "W");
    lv_label_set_text(ui_SP_LabelLoadP, str);
    
    value = (device.meter.powerCurrent.value<0)? -device.meter.powerCurrent.value:device.meter.powerCurrent.value;
    float_to_str(str, value, 3, 6, "A");
    lv_label_set_text(ui_SP_LabelPowerI, str);
    float_to_str(str, device.meter.powerVoltage.value, 2, 6, "V");
    lv_label_set_text(ui_SP_LabelPowerV, str);   
    
    //device.meter.powerPower.value = -6.0;
    //device.meter.loadPower.value = 5;
    if(device.meter.powerPower.value>0.6 || device.meter.powerPower.value<-0.6)
    {
        value = device.meter.loadPower.value/device.meter.powerPower.value;
        if(value>0)
            value*=100;
        else
            value*=-100;
        if(value>99.0)
            value = 99;
    }
    else
        value = 0;
    sprintf(str, "PE%02d%%", (uint16_t)value);
    lv_label_set_text(ui_SP_LabelPE, str);   
    
    if(device.signal.cc_mode.change)
    {
        device.signal.cc_mode.change = 0;
        if(device.signal.cc_mode.value==1)
            lv_label_set_text(ui_Label9, "CC");
        else
            lv_label_set_text(ui_Label9, "CV");
    }
    
    EventBits_t event = xEventGroupWaitBits(xSysEvent, 0x01, pdFALSE, pdTRUE, 0);
    if(event&xSysEvent_PowerReady)
        gui_sp_power_select_refresh();
    if(event&xSysEvent_LoadOE)
    {
        if(device.para.run.load_enable)
            lv_obj_add_state( ui_SP__PanelOE, LV_STATE_CHECKED ); 
        else
            lv_obj_clear_state( ui_SP__PanelOE, LV_STATE_CHECKED ); 
    }
}


void gui_timerRefresh(lv_timer_t *timer)
{
    switch(gui_screen_id)
    {
    case Screen_SP_ID:
        gui_sp_timerRefresh(timer);
        break;
    default:
            
        break;
    }
}
