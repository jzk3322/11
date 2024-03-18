// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.3
// LVGL version: 8.3.6
// Project name: flpower

#ifndef _FLPOWER_UI_H
#define _FLPOWER_UI_H

#ifdef __cplusplus
extern "C" {
#endif

    #include "lvgl/lvgl.h"

#include "ui_helpers.h"
#include "ui_events.h"
void logo_opa_Animation( lv_obj_t *TargetObject, int delay);
// SCREEN: ui_SM_Screen
void ui_SM_Screen_screen_init(void);
void ui_event_SM_Screen( lv_event_t * e);
extern lv_obj_t *ui_SM_Screen;
extern lv_obj_t *ui_SM_PanelLogo;
extern lv_obj_t *ui_SM_LabelLogo1;
extern lv_obj_t *ui_SM_LabelLogo2;
// SCREEN: ui_SP_ScreenPower
void ui_SP_ScreenPower_screen_init(void);
void ui_event_SP_ScreenPower( lv_event_t * e);
extern lv_obj_t *ui_SP_ScreenPower;
extern lv_obj_t *ui_SP_ArcSet;
extern lv_obj_t *ui_SP_LabelSetStep;
extern lv_obj_t *ui_SP_Panel1;
extern lv_obj_t *ui_SP_LabelLoadV;
extern lv_obj_t *ui_SP_LabelLoadI;
extern lv_obj_t *ui_SP_LabelLoadP;
extern lv_obj_t *ui_SP_Panel2;
extern lv_obj_t *ui_SP_LabelPowerV;
extern lv_obj_t *ui_SP_LabelPowerI;
extern lv_obj_t *ui_SP__PanelOE;
extern lv_obj_t *ui_SP_Label6;
extern lv_obj_t *ui_SP_PanelSet;
extern lv_obj_t *ui_SP_LabelSetV;
extern lv_obj_t *ui_SP_LabelSetI;
extern lv_obj_t *ui_SP_Panel5;
extern lv_obj_t *ui_SP_LabelPSelect;
extern lv_obj_t *ui_SP_Panel6;
extern lv_obj_t *ui_SP_LabelPE;
extern lv_obj_t *ui_SP_Panel7;
extern lv_obj_t *ui_Label9;
extern lv_obj_t *ui____initial_actions0;



LV_FONT_DECLARE( ui_font_Font20);
LV_FONT_DECLARE( ui_font_Font40);

void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif