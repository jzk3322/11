// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.3
// LVGL version: 8.3.6
// Project name: flpower

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
void logo_opa_Animation( lv_obj_t *TargetObject, int delay);


// SCREEN: ui_SM_Screen
void ui_SM_Screen_screen_init(void);
void ui_event_SM_Screen( lv_event_t * e);
lv_obj_t *ui_SM_Screen;
lv_obj_t *ui_SM_PanelLogo;
lv_obj_t *ui_SM_LabelLogo1;
lv_obj_t *ui_SM_LabelLogo2;


// SCREEN: ui_SP_ScreenPower
void ui_SP_ScreenPower_screen_init(void);
void ui_event_SP_ScreenPower( lv_event_t * e);
lv_obj_t *ui_SP_ScreenPower;
lv_obj_t *ui_SP_ArcSet;
lv_obj_t *ui_SP_LabelSetStep;
lv_obj_t *ui_SP_Panel1;
lv_obj_t *ui_SP_LabelLoadV;
lv_obj_t *ui_SP_LabelLoadI;
lv_obj_t *ui_SP_LabelLoadP;
lv_obj_t *ui_SP_Panel2;
lv_obj_t *ui_SP_LabelPowerV;
lv_obj_t *ui_SP_LabelPowerI;
lv_obj_t *ui_SP__PanelOE;
lv_obj_t *ui_SP_Label6;
lv_obj_t *ui_SP_PanelSet;
lv_obj_t *ui_SP_LabelSetV;
lv_obj_t *ui_SP_LabelSetI;
lv_obj_t *ui_SP_Panel5;
lv_obj_t *ui_SP_LabelPSelect;
lv_obj_t *ui_SP_Panel6;
lv_obj_t *ui_SP_LabelPE;
lv_obj_t *ui_SP_Panel7;
lv_obj_t *ui_Label9;
lv_obj_t *ui____initial_actions0;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////
void logo_opa_Animation( lv_obj_t *TargetObject, int delay)
{
ui_anim_user_data_t *PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
PropertyAnimation_0_user_data->target = TargetObject;
PropertyAnimation_0_user_data->val = -1;
lv_anim_t PropertyAnimation_0;
lv_anim_init(&PropertyAnimation_0);
lv_anim_set_time(&PropertyAnimation_0, 2000);
lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity );
lv_anim_set_values(&PropertyAnimation_0, 0, 255 );
lv_anim_set_path_cb( &PropertyAnimation_0, lv_anim_path_ease_out);
lv_anim_set_delay( &PropertyAnimation_0, delay + 0 );
lv_anim_set_deleted_cb( &PropertyAnimation_0, _ui_anim_callback_free_user_data );
lv_anim_set_playback_time(&PropertyAnimation_0, 0);
lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
 lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
lv_anim_set_early_apply( &PropertyAnimation_0, false );
lv_anim_start(&PropertyAnimation_0);
ui_anim_user_data_t *PropertyAnimation_1_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
PropertyAnimation_1_user_data->target = TargetObject;
PropertyAnimation_1_user_data->val = -1;
lv_anim_t PropertyAnimation_1;
lv_anim_init(&PropertyAnimation_1);
lv_anim_set_time(&PropertyAnimation_1, 1000);
lv_anim_set_user_data(&PropertyAnimation_1, PropertyAnimation_1_user_data);
lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_opacity );
lv_anim_set_values(&PropertyAnimation_1, 255, 0 );
lv_anim_set_path_cb( &PropertyAnimation_1, lv_anim_path_ease_out);
lv_anim_set_delay( &PropertyAnimation_1, delay + 2000 );
lv_anim_set_deleted_cb( &PropertyAnimation_1, _ui_anim_callback_free_user_data );
lv_anim_set_playback_time(&PropertyAnimation_1, 0);
lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
 lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
lv_anim_set_early_apply( &PropertyAnimation_1, false );
lv_anim_start(&PropertyAnimation_1);

}

///////////////////// FUNCTIONS ////////////////////
void ui_event_SM_Screen( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_SCREEN_LOADED) {
      logo_opa_Animation(ui_SM_PanelLogo, 0);
      _ui_screen_change( &ui_SP_ScreenPower, LV_SCR_LOAD_ANIM_FADE_ON, 500, 3000, &ui_SP_ScreenPower_screen_init);
}
}
void ui_event_SP_ScreenPower( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_SCREEN_LOAD_START) {
      sp_screen_in( e );
     // ( e );
}
}

///////////////////// SCREENS ////////////////////

void ui_init( void )
{
lv_disp_t *dispp = lv_disp_get_default();
lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
lv_disp_set_theme(dispp, theme);
ui_SM_Screen_screen_init();
ui_SP_ScreenPower_screen_init();
ui____initial_actions0 = lv_obj_create(NULL);
lv_disp_load_scr( ui_SM_Screen);
}
