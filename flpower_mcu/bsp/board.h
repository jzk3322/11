
#ifndef BOARD_H
#define BOARD_H

#include <stdlib.h>
#include <string.h>


#include "bsp.h"

#include "component.h"
#include "sys_log.h"

#define LCD_X_SIZE      (240)
#define LCD_Y_SIZE      (240)

enum
{
    BoardSerialDebugID = 0,  
};

typedef struct{
    Key left;
    Key right;
    Key power;
    uint16_t debounce_time; //防抖时间
    SemaphoreHandle_t event_change;
}board_key_t;

typedef struct{
    GpioHandle enable;
    GpioHandle ce;
    GeneralOut current;
    GeneralOut voltage;
}board_power_out_t;


typedef struct
{
    Led led_run;
    Encoder encoder;
    board_key_t switch_group;
    FUSB302_dev_t fusb302;
    INA226 ina226_power;
    INA226 ina226_load;
    GpioHandle fusb302_int_gpio_handle;
    board_power_out_t power_out;
}Board;

extern Board board;
extern void board_init(void);
extern int board_serial_send(uint8_t id, const char *buffer, uint32_t length);
extern uint8_t BoardSwitchGroupScan(uint16_t ms);
extern void BoardTimerTask(uint16_t ms);
#endif
