#include "general_in.h"
#include <string.h>

/* 扫描输入，进行防抖计时，返回按键状态是否有变化 */
uint8_t GeneralInScan(GeneralIn *in, uint16_t debounce_time, uint16_t tick)
{
    uint8_t level = in->m->get(in) ^ in->reverse;
    if(in->debounce_flag) //处于防抖中
    {
        in->debounce_cnt += tick;
        if(in->debounce_cnt>debounce_time)
        {
            in->debounce_flag = 0;
            in->state = level;
            if(in->state!=in->state_old)
            {
                in->state_old = in->state;
                in->change = 1;
                return 1;
            }    
        }
    }
    else if(level != in->state)
    {
        in->debounce_flag = 1;
        in->debounce_cnt = 0;
    }
    return 0;
}

uint8_t GpioGeneralInGet(GeneralIn *in)
{
    GpioHandle *handle = in->hw_port;
    return GpioGetValue(handle);
}

const GeneralInMethod gpioGeneralInMethod = {
    .get = GpioGeneralInGet,
};

void GpioGeneralInInit(GeneralIn *in, GpioHandle *handle, uint8_t reverse)
{
    memset(in, 0, sizeof(GeneralIn));
    in->hw_port = (void *)handle;
    in->reverse = reverse;
    in->m = &gpioGeneralInMethod;
}