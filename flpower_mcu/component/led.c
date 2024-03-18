#include "led.h"

void LedBreath(Led *led, uint16_t add)
{
    int16_t val = led->level;
    if(led->addDir)
    {
        val += add;
        if(val>=led->levle_max)
        {
            val = led->levle_max;
            led->addDir = 0;
        }
    }
    else
    {
        val -= add;
        if(val<=0)
        {
            val = 0;
            led->addDir = 1;
        }
    }
    LedOn(led, val);
}