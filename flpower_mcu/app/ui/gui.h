#ifndef LV_GUI_H
#define LV_GUI_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef LV_GUI_SIMULATE
#define LV_GUI_SIMULATE 0
#endif // LV_GUI_SIMULATE


#include "lvgl/porting/lv_port_disp.h"
//#include "lvgl/porting/lv_port_indev.h"
//#include "lvgl/demos/lv_demos.h"
/*********************
 *      INCLUDES
 *********************/
#if LV_GUI_SIMULATE==1
#include "lv_drivers/win32drv/win32drv.h"
#else
#include "lvgl/lvgl.h"

#include "lvgl/src/hal/lv_hal_tick.h"

//#define printf
#endif // LV_GUI_SIMULATE

#include "ui.h"
/*********************
 *      DEFINES
 *********************/
 
/**********************
 *      TYPEDEFS
 **********************/
enum {
    Screen_SM_ID = 0,
  Screen_SP_ID = 1,  
};

/**********************
 * GLOBAL PROTOTYPES
 **********************/
extern lv_group_t*  g_default;
extern int16_t time_cnt;
extern uint8_t gui_screen_id;
extern lv_obj_t *gui_screen_list[];

/* */
extern void gui_init(void);
extern void gui_timerRefresh(lv_timer_t *timer);
//---------------------------------------------------------------------------
extern void gui_sp_set_refresh(void);
extern void gui_sp_value_select(uint8_t obj_id);
extern void gui_sp_value_step_select(uint8_t obj_step_id);
extern void gui_sp_power_select_refresh(void);
//---------------------------------------------------------------------------
extern void gui_indev_event(void);
/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* LV_GUI_H */
