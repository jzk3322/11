
#include "gui.h"

int16_t time_cnt;
lv_group_t*  g_default;
lv_timer_t *lv_timer;
uint8_t gui_screen_id;

void gui_init(void)
{
    g_default = lv_group_create();
    lv_group_set_default(g_default);
#if LV_GUI_SIMULATE==1
    lv_indev_set_group(lv_win32_encoder_device_object, g_default);
#else
    ;//lv_indev_set_group(indev_encoder, g_default);
#endif
    //gui_MainWinCreate(&guiMainWin, lv_scr_act());
    ui_init();
    time_cnt = -1;
    lv_timer = lv_timer_create(gui_timerRefresh, 300, NULL);
}
