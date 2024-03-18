//led设备

#ifndef LED_H
#define LED_H

#include "general_out.h"

typedef enum {
    kLedLevel0 = 0,
    kLedLevel1 = GENERAL_OUT_LEVEL_MAX>>3,
    kLedLevel2 = GENERAL_OUT_LEVEL_MAX>>2,
    kLedLevel3 = GENERAL_OUT_LEVEL_MAX>>1,
    kLedLevel4 = GENERAL_OUT_LEVEL_MAX,
}LedLevel;

typedef GeneralOut Led;

static inline void LedOn(Led *led, GeneralOutLevel level)
{
    if(level==0)
        led->m->off(led);
    else
        led->m->on(led, level);
}

static inline void LedOff(Led *led)
{
    led->m->off(led);
}

static inline void LedToggle(Led *led)
{
    led->m->toggle(led);
}

#define GpioLedInit  GpioGeneralOutInit
#define PwmLedInit   PwmGeneralOutInit

extern void LedBreath(Led *led, uint16_t add);

#endif