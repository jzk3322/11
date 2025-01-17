// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.3
// LVGL version: 8.3.6
// Project name: flpower

#include "../ui.h"

void ui_SP_ScreenPower_screen_init(void)
{
ui_SP_ScreenPower = lv_obj_create(NULL);
lv_obj_clear_flag( ui_SP_ScreenPower, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_text_font(ui_SP_ScreenPower, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SP_ArcSet = lv_arc_create(ui_SP_ScreenPower);
lv_obj_set_width( ui_SP_ArcSet, 70);
lv_obj_set_height( ui_SP_ArcSet, 70);
lv_obj_set_x( ui_SP_ArcSet, 0 );
lv_obj_set_y( ui_SP_ArcSet, 80 );
lv_obj_set_align( ui_SP_ArcSet, LV_ALIGN_CENTER );
lv_obj_set_style_arc_width(ui_SP_ArcSet, 15, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_arc_color(ui_SP_ArcSet, lv_color_hex(0x00FF00), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_arc_opa(ui_SP_ArcSet, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_arc_width(ui_SP_ArcSet, 15, LV_PART_INDICATOR| LV_STATE_DEFAULT);

lv_obj_set_style_opa(ui_SP_ArcSet, 0, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_SP_LabelSetStep = lv_label_create(ui_SP_ArcSet);
lv_obj_set_width( ui_SP_LabelSetStep, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_SP_LabelSetStep, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_SP_LabelSetStep, LV_ALIGN_CENTER );
lv_label_set_text(ui_SP_LabelSetStep,"1.00");
lv_obj_set_style_text_color(ui_SP_LabelSetStep, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_SP_LabelSetStep, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_SP_LabelSetStep, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SP_Panel1 = lv_obj_create(ui_SP_ScreenPower);
lv_obj_set_width( ui_SP_Panel1, 156);
lv_obj_set_height( ui_SP_Panel1, 150);
lv_obj_set_x( ui_SP_Panel1, -38 );
lv_obj_set_y( ui_SP_Panel1, -42 );
lv_obj_set_align( ui_SP_Panel1, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_SP_Panel1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_SP_Panel1, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_SP_Panel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_SP_Panel1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_SP_Panel1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SP_LabelLoadV = lv_label_create(ui_SP_Panel1);
lv_obj_set_width( ui_SP_LabelLoadV, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_SP_LabelLoadV, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_SP_LabelLoadV, 0 );
lv_obj_set_y( ui_SP_LabelLoadV, -5 );
lv_obj_set_align( ui_SP_LabelLoadV, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_SP_LabelLoadV,"12.01V");
lv_obj_set_style_text_color(ui_SP_LabelLoadV, lv_color_hex(0x00FF00), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_SP_LabelLoadV, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_SP_LabelLoadV, &ui_font_Font40, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SP_LabelLoadI = lv_label_create(ui_SP_Panel1);
lv_obj_set_width( ui_SP_LabelLoadI, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_SP_LabelLoadI, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_SP_LabelLoadI, LV_ALIGN_CENTER );
lv_label_set_text(ui_SP_LabelLoadI,"1.004A");
lv_obj_set_style_text_color(ui_SP_LabelLoadI, lv_color_hex(0x00FFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_SP_LabelLoadI, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_SP_LabelLoadI, &ui_font_Font40, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SP_LabelLoadP = lv_label_create(ui_SP_Panel1);
lv_obj_set_width( ui_SP_LabelLoadP, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_SP_LabelLoadP, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_SP_LabelLoadP, 0 );
lv_obj_set_y( ui_SP_LabelLoadP, 5 );
lv_obj_set_align( ui_SP_LabelLoadP, LV_ALIGN_BOTTOM_MID );
lv_label_set_text(ui_SP_LabelLoadP,"12.20W");
lv_obj_set_style_text_color(ui_SP_LabelLoadP, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_SP_LabelLoadP, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_SP_LabelLoadP, &ui_font_Font40, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SP_Panel2 = lv_obj_create(ui_SP_ScreenPower);
lv_obj_set_width( ui_SP_Panel2, 70);
lv_obj_set_height( ui_SP_Panel2, 60);
lv_obj_set_x( ui_SP_Panel2, -77 );
lv_obj_set_y( ui_SP_Panel2, 76 );
lv_obj_set_align( ui_SP_Panel2, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_SP_Panel2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_SP_Panel2, 10, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SP_LabelPowerV = lv_label_create(ui_SP_Panel2);
lv_obj_set_width( ui_SP_LabelPowerV, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_SP_LabelPowerV, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_SP_LabelPowerV, 0 );
lv_obj_set_y( ui_SP_LabelPowerV, -15 );
lv_obj_set_align( ui_SP_LabelPowerV, LV_ALIGN_CENTER );
lv_label_set_text(ui_SP_LabelPowerV,"20.01V");
lv_obj_set_style_text_color(ui_SP_LabelPowerV, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_SP_LabelPowerV, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_SP_LabelPowerV, &ui_font_Font20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SP_LabelPowerI = lv_label_create(ui_SP_Panel2);
lv_obj_set_width( ui_SP_LabelPowerI, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_SP_LabelPowerI, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_SP_LabelPowerI, 0 );
lv_obj_set_y( ui_SP_LabelPowerI, 15 );
lv_obj_set_align( ui_SP_LabelPowerI, LV_ALIGN_CENTER );
lv_label_set_text(ui_SP_LabelPowerI,"1.082A");
lv_obj_set_style_text_color(ui_SP_LabelPowerI, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_SP_LabelPowerI, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_SP_LabelPowerI, &ui_font_Font20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SP__PanelOE = lv_obj_create(ui_SP_ScreenPower);
lv_obj_set_width( ui_SP__PanelOE, 70);
lv_obj_set_height( ui_SP__PanelOE, 30);
lv_obj_set_x( ui_SP__PanelOE, 80 );
lv_obj_set_y( ui_SP__PanelOE, -100 );
lv_obj_set_align( ui_SP__PanelOE, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_SP__PanelOE, LV_OBJ_FLAG_CHECKABLE );   /// Flags
lv_obj_clear_flag( ui_SP__PanelOE, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_SP__PanelOE, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_SP__PanelOE, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_SP__PanelOE, lv_color_hex(0x00FF00), LV_PART_MAIN | LV_STATE_CHECKED );
lv_obj_set_style_bg_opa(ui_SP__PanelOE, 255, LV_PART_MAIN| LV_STATE_CHECKED);

ui_SP_Label6 = lv_label_create(ui_SP__PanelOE);
lv_obj_set_width( ui_SP_Label6, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_SP_Label6, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_SP_Label6, LV_ALIGN_CENTER );
lv_label_set_text(ui_SP_Label6,"ON");
lv_obj_set_style_text_color(ui_SP_Label6, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_SP_Label6, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_SP_Label6, &ui_font_Font20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SP_PanelSet = lv_obj_create(ui_SP_ScreenPower);
lv_obj_set_width( ui_SP_PanelSet, 70);
lv_obj_set_height( ui_SP_PanelSet, 60);
lv_obj_set_x( ui_SP_PanelSet, 79 );
lv_obj_set_y( ui_SP_PanelSet, 76 );
lv_obj_set_align( ui_SP_PanelSet, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_SP_PanelSet, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_SP_PanelSet, lv_color_hex(0x00FF00), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_SP_PanelSet, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_SP_PanelSet, lv_color_hex(0x00FF00), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_SP_PanelSet, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SP_LabelSetV = lv_label_create(ui_SP_PanelSet);
lv_obj_set_width( ui_SP_LabelSetV, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_SP_LabelSetV, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_SP_LabelSetV, 0 );
lv_obj_set_y( ui_SP_LabelSetV, -5 );
lv_obj_set_align( ui_SP_LabelSetV, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_SP_LabelSetV,"05.00V");
lv_obj_set_style_text_color(ui_SP_LabelSetV, lv_color_hex(0x00FF00), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_SP_LabelSetV, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_SP_LabelSetV, &ui_font_Font20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SP_LabelSetI = lv_label_create(ui_SP_PanelSet);
lv_obj_set_width( ui_SP_LabelSetI, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_SP_LabelSetI, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_SP_LabelSetI, 0 );
lv_obj_set_y( ui_SP_LabelSetI, 5 );
lv_obj_set_align( ui_SP_LabelSetI, LV_ALIGN_BOTTOM_MID );
lv_label_set_text(ui_SP_LabelSetI,"01.00A");
lv_obj_set_style_text_color(ui_SP_LabelSetI, lv_color_hex(0x00FFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_SP_LabelSetI, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_SP_LabelSetI, &ui_font_Font20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SP_Panel5 = lv_obj_create(ui_SP_ScreenPower);
lv_obj_set_width( ui_SP_Panel5, 70);
lv_obj_set_height( ui_SP_Panel5, 30);
lv_obj_set_x( ui_SP_Panel5, 80 );
lv_obj_set_y( ui_SP_Panel5, -64 );
lv_obj_set_align( ui_SP_Panel5, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_SP_Panel5, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_SP_Panel5, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_SP_Panel5, lv_color_hex(0xA8CFB8), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_SP_Panel5, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_SP_Panel5, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SP_LabelPSelect = lv_label_create(ui_SP_Panel5);
lv_obj_set_width( ui_SP_LabelPSelect, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_SP_LabelPSelect, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_SP_LabelPSelect, LV_ALIGN_CENTER );
lv_label_set_text(ui_SP_LabelPSelect,"20V4.5A");
lv_obj_set_style_text_color(ui_SP_LabelPSelect, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_SP_LabelPSelect, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_SP_LabelPSelect, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SP_Panel6 = lv_obj_create(ui_SP_ScreenPower);
lv_obj_set_width( ui_SP_Panel6, 70);
lv_obj_set_height( ui_SP_Panel6, 30);
lv_obj_set_x( ui_SP_Panel6, 80 );
lv_obj_set_y( ui_SP_Panel6, -28 );
lv_obj_set_align( ui_SP_Panel6, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_SP_Panel6, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_SP_Panel6, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_SP_Panel6, lv_color_hex(0xFFFF00), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_SP_Panel6, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_SP_Panel6, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SP_LabelPE = lv_label_create(ui_SP_Panel6);
lv_obj_set_width( ui_SP_LabelPE, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_SP_LabelPE, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_SP_LabelPE, LV_ALIGN_CENTER );
lv_label_set_text(ui_SP_LabelPE,"PE85%");
lv_obj_set_style_text_color(ui_SP_LabelPE, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_SP_LabelPE, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_SP_LabelPE, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SP_Panel7 = lv_obj_create(ui_SP_ScreenPower);
lv_obj_set_width( ui_SP_Panel7, 70);
lv_obj_set_height( ui_SP_Panel7, 30);
lv_obj_set_x( ui_SP_Panel7, 80 );
lv_obj_set_y( ui_SP_Panel7, 9 );
lv_obj_set_align( ui_SP_Panel7, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_SP_Panel7, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_SP_Panel7, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_SP_Panel7, lv_color_hex(0xABA8E6), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_SP_Panel7, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_SP_Panel7, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label9 = lv_label_create(ui_SP_Panel7);
lv_obj_set_width( ui_Label9, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label9, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label9, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label9,"CV");
lv_obj_set_style_text_color(ui_Label9, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label9, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label9, &ui_font_Font20, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_SP_ScreenPower, ui_event_SP_ScreenPower, LV_EVENT_ALL, NULL);

}
