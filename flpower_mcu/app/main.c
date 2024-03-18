
#include "app_includes.h"

int main(void)
{
    bsp_init();
    
    xTaskCreate( appCreatTask, "task_init", 128, NULL, 5, NULL );
	/* Start the scheduler. */
	vTaskStartScheduler();
	/* Will only get here if there was not enough heap space to create the
	idle task. */
	return 0;
}



void xPortSysTickHandler( void );
void SysTick_Handler( void )
{
    if (xTaskGetSchedulerState() != taskSCHEDULER_NOT_STARTED)
    {
        xPortSysTickHandler();
    }
}


void vApplicationTickHook()
{
    static uint8_t cnt_ms = 0;
	static BaseType_t xHigherPriorityTaskWoken;
    //vcomRxTimeCnt(1);
    if(app_init_flag)
    {       
        lv_tick_inc(1);
        BoardTimerTask(1);
        cnt_ms++;
        if(!(cnt_ms&15))
        {
            xSemaphoreGiveFromISR(xSemaphoreSample,&xHigherPriorityTaskWoken);
        }
    }
}


