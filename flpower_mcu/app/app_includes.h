#ifndef INCLUDES_H
#define INCLUDES_H

//#include "version.h"

#include "board.h"

#include "string_extend.h"

#include "app_pd.h"
#include "app_pd_log.h"
#include "device.h"
#include "version.h"
#include "gui.h"

#undef EXTERN
#ifndef APP_INIT_C
#define EXTERN extern
#else
#define EXTERN
#endif

enum{
    xSysEvent_PowerReady = 1<<0,  
    xSysEvent_LoadOE = 1<<1,
};

EXTERN SemaphoreHandle_t xSemaphoreSample;
EXTERN EventGroupHandle_t xSysEvent;

extern uint8_t app_init_flag;

extern void app_init(void);
extern void appCreatTask(void *para);

extern void task_gui(void *para);
extern void task_pd(void *para);
extern void task_log(void *para);
extern void task_sample(void *para);

extern void power_out(uint8_t enable);
extern void power_set_voltage(uint16_t v);
extern void power_set_current(uint16_t i);
#endif
