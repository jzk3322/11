
#include "app_includes.h"

static uint16_t *set_value[] = {&device.para.run.load_v_set, &device.para.run.load_i_set};
static uint16_t *set_value_max[] = {&device.para.store.load_v_max, &device.para.store.load_i_max};
static uint32_t set_color[] = {0x00FF00, 0x00FFFF};

static uint8_t set_value_id;

static const uint16_t sp_set_step[] = {10, 100, 1000};
static uint8_t set_step_id;

void gui_sp_value_select(uint8_t obj_id)
{
    char str[16];
    
    if(obj_id>1)
        return;
    set_value_id = obj_id;
    //设置圆弧范围和值
    lv_arc_set_range(ui_SP_ArcSet, 0, *set_value_max[set_value_id]);
    lv_arc_set_value(ui_SP_ArcSet, *set_value[set_value_id]);
    //设置面板对应颜色
    lv_obj_set_style_border_color(ui_SP_PanelSet, lv_color_hex(set_color[set_value_id]), LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_obj_set_style_arc_color(ui_SP_ArcSet, lv_color_hex(set_color[set_value_id]), LV_PART_INDICATOR | LV_STATE_DEFAULT );
}

void gui_sp_value_step_select(uint8_t obj_step_id)
{
    char str[16];
    if(obj_step_id>2)
        return ;
    set_step_id = obj_step_id;
    uint_to_str(str, sp_set_step[obj_step_id]/10, 2, 4, 0);
    lv_label_set_text(ui_SP_LabelSetStep, str);
}

/* power界面按键处理 */
void gui_sp_screen_indev_event(void)
{
    static int32_t value;
    int32_t diff = board.encoder.diff;
    board.encoder.diff = 0;
    if(diff!=0)
    {
        value = diff*sp_set_step[set_step_id] + *set_value[set_value_id];
        if(value<0)
            *set_value[set_value_id] = 0;
        else if(value>*set_value_max[set_value_id])
            *set_value[set_value_id] = *set_value_max[set_value_id];
        else
            *set_value[set_value_id] = value;
        lv_arc_set_value(ui_SP_ArcSet, *set_value[set_value_id]);
        gui_sp_set_refresh();
        //设置pwm
        power_set_voltage(device.para.run.load_v_set);
        power_set_current(device.para.run.load_i_set);
    }
    if(board.encoder.key_change && board.encoder.key==0)
    {
        board.encoder.key_change = 0;
        set_step_id++;
        if(set_step_id==3)
            set_step_id = 0;
        gui_sp_value_step_select(set_step_id);
    }
    if(board.switch_group.right.change && board.switch_group.right.state==0) //right键抬起
    {
        board.switch_group.right.change = 0;
        gui_sp_value_select(set_value_id^1);
    }
    if(board.switch_group.power.change && board.switch_group.power.state==0) //power键
    {
        board.switch_group.power.change = 0;
        device.para.run.load_enable ^= 1;
        power_out(device.para.run.load_enable);
        xEventGroupSetBits(xSysEvent, xSysEvent_LoadOE);
    }
}

void gui_indev_event(void)
{
    switch(gui_screen_id)
    {
        case Screen_SP_ID:
            gui_sp_screen_indev_event();
    }
}