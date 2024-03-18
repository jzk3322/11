//通用输出设备

#ifndef GENERAL_OUT_H
#define GENERAL_OUT_H

#include "hal_rtos_drv.h"

#define GENERAL_OUT_LEVEL_MAX       (65535ul)
typedef uint16_t GeneralOutLevel;

struct _GeneralOut;

typedef void (*GeneralOutOn)(struct _GeneralOut *out, GeneralOutLevel level);
typedef void (*GeneralOutOff)(struct _GeneralOut *out);
typedef void (*GeneralOutToggle)(struct _GeneralOut *out);

typedef struct _GeneralOutMethod
{
     GeneralOutOn on;
     GeneralOutOff off;
     GeneralOutToggle toggle;
}GeneralOutMethod;

typedef struct _GeneralOut
{
    void *hw_port; //硬件驱动端口
    GeneralOutMethod const *m; //方法
    uint8_t type; //类型
    uint8_t reverse:1; //反转
    uint8_t state:1; //状态
    uint8_t addDir:1; //呼吸模式累加方向
    uint8_t :5;
    GeneralOutLevel level; //输出等级
    GeneralOutLevel levle_max;
}GeneralOut;
/* method api */
extern const GeneralOutMethod gpioGeneralOutMethod;
extern const GeneralOutMethod pwmGeneralOutMethod;
/* init api */
extern void GpioGeneralOutInit(GeneralOut *out, GpioHandle *port, uint8_t reverse, GeneralOutLevel level_max);
extern void PwmGeneralOutInit(GeneralOut *out, PwmHandle *port, uint8_t reverse, uint32_t freq, GeneralOutLevel level_max);

extern void PwmGeneralOutOn(GeneralOut *out, GeneralOutLevel level);
extern void PwmGeneralOutOff(GeneralOut *out);
extern void PwmGeneralOutToogle(GeneralOut *out);
#endif