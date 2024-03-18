
#ifndef BSP_H
#define BSP_H

#include <stdio.h>
#include "air32f10x.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

#include "hal_rtos_i2c.h"
#include "hal_simulate_i2c.h"

#define BSP_LCD_RST_PORT    GPIOA
#define BSP_LCD_RST_GPIO    GPIO_Pin_15
#define BSP_LCD_CS_PORT     GPIOB
#define BSP_LCD_CS_GPIO     GPIO_Pin_12
#define BSP_LCD_DC_PORT     GPIOB
#define BSP_LCD_DC_GPIO     GPIO_Pin_14
#define BSP_LCD_SPI         SPI2
#define BSP_LCD_DMA_CH      DMA1_Channel5

#define BSP_PWR_PWM_PERIOD      (5000)

extern uint32_t SystemCoreClock;

extern void bsp_init(void);

extern void bsp_delay_block(uint32_t ms);

#endif
