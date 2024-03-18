#include "general_out.h"

/**
 * gpio类API，
 * 在GpioGeneralOutOn()中，level小于out->levle_max的一半时，相当于输出0
 */
void GpioGeneralOutOn(GeneralOut *out, GeneralOutLevel level)
{
    GpioHandle *gpio = out->hw_port;
    out->state = level>(out->levle_max>>1);
    GpioSetValue(gpio, out->state^out->reverse);
}

void GpioGeneralOutOff(GeneralOut *out)
{
    GpioHandle *gpio = out->hw_port;
    out->state = 0;
    GpioSetValue(gpio, out->state^out->reverse);
}

void GpioGeneralOutToogle(GeneralOut *out)
{
    GpioHandle *gpio = out->hw_port;
    out->state ^= 1;
    GpioSetValue(gpio, out->state^out->reverse);
}

const GeneralOutMethod gpioGeneralOutMethod = {
    .on = GpioGeneralOutOn,
    .off = GpioGeneralOutOff,
    .toggle = GpioGeneralOutToogle,
};

/**
 * pwm类API，
 */
void PwmGeneralOutOn(GeneralOut *out, GeneralOutLevel level)
{
    PwmHandle *pwm = out->hw_port;
    out->state = 1;
    out->level = level>out->levle_max?out->levle_max:level;
    HalPwmEnable(pwm);
    HalPwmSetDuty(pwm, out->reverse?out->levle_max-out->level:out->level, out->levle_max);
}

void PwmGeneralOutOff(GeneralOut *out)
{
    PwmHandle *pwm = out->hw_port;
    out->state = 0;
    out->level = 0;
    HalPwmDisable(pwm);
    //HalPwmSetDuty(pwm, out->reverse?out->levle_max-out->level:out->level, out->levle_max);
}

void PwmGeneralOutToogle(GeneralOut *out)
{
    PwmHandle *pwm = out->hw_port;
    out->state ^= 1;
    out->level = out->levle_max - out->level;
    HalPwmSetDuty(pwm, out->reverse?out->levle_max-out->level:out->level, out->levle_max);
}

const GeneralOutMethod pwmGeneralOutMethod = {
    .on = PwmGeneralOutOn,
    .off = PwmGeneralOutOff,
    .toggle = PwmGeneralOutToogle,
};

void GpioGeneralOutInit(GeneralOut *out, GpioHandle *port, uint8_t reverse, GeneralOutLevel level_max)
{
    out->hw_port = (void *)port;
    out->reverse = reverse;
    out->m = &gpioGeneralOutMethod;
    out->state = 0;
    out->levle_max = level_max;
    //out->m->off(out);
}

void PwmGeneralOutInit(GeneralOut *out, PwmHandle *port, uint8_t reverse, uint32_t freq, GeneralOutLevel level_max)
{
    out->hw_port = (void *)port;
    out->reverse = reverse;
    out->m = &pwmGeneralOutMethod;
    out->state = 0;
    out->levle_max = level_max;
    //HalPwmConfig(port, freq);
    out->m->off(out);
}
