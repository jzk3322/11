#include "encoder.h"

void GpioEncoderInit(Encoder *enc, GpioEncoderHandle *handle)
{
    enc->handle = handle;
    enc->diff = 0;
    enc->key = 0;
}

void EncoderScan(Encoder *enc, uint16_t debounce_time, uint16_t tick)
{
    uint8_t value_a = GpioGetValue(&enc->handle->a);
    uint8_t value_b = GpioGetValue(&enc->handle->b);

    if(value_a==1 && value_b==1)
        enc->lock = 0;
    else if(enc->lock==0 && value_a==0 && value_b==1)
    {
        enc->lock = 1;
        enc->diff++;
    }
    else if(enc->lock==0 && value_a==1 && value_b==0)
    {
        enc->lock = 1;
        enc->diff--;
    }

    uint8_t value_k = !GpioGetValue(&enc->handle->k);
    if(enc->debounce_flag) //处于防抖中
    {
        enc->debounce_cnt += tick;
        if(enc->debounce_cnt>debounce_time)
        {
            enc->debounce_flag = 0;
            enc->key = value_k; 
            enc->key_change = 1;
        }
    }
    else if(value_k != enc->key)
    {
        enc->debounce_flag = 1;
        enc->debounce_cnt = 0;
    }    
}