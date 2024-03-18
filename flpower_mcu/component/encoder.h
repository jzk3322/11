//旋转编码器
#ifndef ENCODER_H
#define ENCODER_H

#include "hal_rtos_drv.h"

typedef struct 
{
    GpioHandle a;
    GpioHandle b;
    GpioHandle k;
}GpioEncoderHandle;

typedef struct _Encoder
{
    GpioEncoderHandle *handle;
    uint16_t debounce_cnt;
    uint16_t lock:1;
    uint16_t key:1; //状态
    uint16_t key_change:1;
    uint16_t debounce_flag:1; //进入防抖阶段
    int16_t diff; //步进值
}Encoder;

#define EncoderClearDiff(enc)   (enc)->diff = 0

extern void GpioEncoderInit(Encoder *enc, GpioEncoderHandle *handle);
extern void EncoderScan(Encoder *enc, uint16_t debounce_time, uint16_t tick);
#endif
