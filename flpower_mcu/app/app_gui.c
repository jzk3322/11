
#include "app_includes.h"
#include "gui.h"

//extern void lv_example_arc_2(void);

void task_gui(void *para)
{
    lv_init();
    lv_port_disp_init();
    //lv_port_indev_init();
    
    TickType_t xLastWakeTime;
    const TickType_t xPeriod = pdMS_TO_TICKS( 1 );

    xLastWakeTime = xTaskGetTickCount();  
    //lv_example_get_started_1();
    //lv_example_anim_3();
    //lv_example_arc_2();
    gui_init();
    while(1)
    {
        vTaskDelayUntil( &xLastWakeTime,xPeriod );
        lv_timer_handler();   
        gui_indev_event();      
    }
    vTaskDelete(NULL);
}
