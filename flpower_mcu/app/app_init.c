
#define APP_INIT_C
#include "app_includes.h"

uint8_t app_init_flag = 0;

void app_init(void)
{
    board_init();
    /* add semaphores, ... */
    xSemaphoreSample = xSemaphoreCreateBinary();
    xSysEvent = xEventGroupCreate();
    //lcd_dma_complete_flag = xSemaphoreCreateBinary();
    deviceInit();
    //关闭电源输出
    power_out(0);
    power_set_voltage(device.para.run.load_v_set);
    power_set_current(device.para.run.load_i_set);
    app_init_flag = 1;
}


#define mainCREATOR_TASK_PRIORITY           ( tskIDLE_PRIORITY + 3 )
#define TASK_PRORITY_LED 3

static void task_led(void *pvParameters)
{
    volatile float voltage, power, current;
    GPIO_SetBits(GPIOA, GPIO_Pin_8);
    while(1) {
        LedBreath(&board.led_run,500);
        //voltage = ina226_get_voltage(&board.ina226_power);
        //power = ina226_get_power(&board.ina226_power);
        //current = ina226_get_current(&board.ina226_power);
        vTaskDelay(pdMS_TO_TICKS(100));
    }
    vTaskDelete( NULL );
}

void appCreatTask(void *para)
{
    app_init();
    xTaskCreate(task_sample, "task_sample", 128, NULL, 6, NULL );
    xTaskCreate(task_led, "task_led", 128, NULL, TASK_PRORITY_LED, NULL );
    xTaskCreate(task_gui, (const char *)"lvgl", 1024, NULL, 2, NULL);
    xTaskCreate(task_pd, "task_pd", 256, NULL, 5, NULL );
    xTaskCreate(task_log, "task_log", 128, NULL, 6, NULL );
    vTaskDelete(NULL);
}