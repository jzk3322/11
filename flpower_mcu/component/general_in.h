//通用输出设备

#ifndef GENERAL_IN_H
#define GENERAL_IN_H

#include "hal_rtos_drv.h"

struct _GeneralIn;

typedef uint8_t (*GeneralInGet)(struct _GeneralIn *in);

typedef struct _GeneralInMethod
{
     GeneralInGet get;
}GeneralInMethod;

typedef struct _GeneralIn
{
    void *hw_port; //硬件驱动端口
    GeneralInMethod const *m; //方法
    uint16_t debounce_cnt;
    uint16_t reverse:1; //反转
    uint16_t state:2; //状态
    uint16_t state_old:2;
    uint16_t debounce_flag:1; //进入防抖阶段
    uint16_t change:1; //变化标识
}GeneralIn;
/* method api */
extern const GeneralInMethod gpioGeneralInMethod;
/* init api */
extern void GpioGeneralInInit(GeneralIn *in, GpioHandle *port, uint8_t reverse);

extern uint8_t GeneralInScan(GeneralIn *in, uint16_t debounce_time, uint16_t tick);
#endif
