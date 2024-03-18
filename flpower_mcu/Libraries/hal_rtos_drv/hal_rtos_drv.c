#include "hal_rtos_drv.h"

GPIO_TypeDef *gpio_group[] = {GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF, GPIOG};

/**
 * pwm api 
 * 
 */
static TIM_TypeDef *pwm_base[] = {TIM1,TIM2,TIM3,TIM4,};

void HalPwmConfig(PwmHandle *pwm, uint32_t freq)
{    
    TIM_DeInit(pwm_base[pwm->group-1]);
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_TimeBaseStructure.TIM_Prescaler = 0;					// 预分频器
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; // 向上计数模式
	TIM_TimeBaseStructure.TIM_Period = (SystemCoreClock / freq) - 1;				// 自动重装载值，定时器周期为17570Hz
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;				// 时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 2;			// 重复计数器
	TIM_TimeBaseInit(pwm_base[pwm->group-1], &TIM_TimeBaseStructure); // 初始化定时器1
}

void HalPwmEnable(PwmHandle *pwm)
{
    ;
}

void HalPwmDisable(PwmHandle *pwm)
{
    ;
}

void HalPwmSetDuty(PwmHandle *pwm, uint32_t duty, uint32_t duty_max)
{
    uint16_t new_ccr = pwm_base[pwm->group-1]->ARR *duty / duty_max;
    if(duty>=duty_max)
        new_ccr += 1;
    switch(pwm->ch)
    {
        case 1:
            TIM_SetCompare1(pwm_base[pwm->group-1], new_ccr);
            break;
        case 2:
            TIM_SetCompare2(pwm_base[pwm->group-1], new_ccr);
            break;
        case 3:
            TIM_SetCompare3(pwm_base[pwm->group-1], new_ccr);
            break;
        case 4:
            TIM_SetCompare4(pwm_base[pwm->group-1], new_ccr);
            break;
        default:
            break;
    }
}

void hal_delay_us_block(uint32_t us)
{
    volatile uint32_t i;
    while(us--)
    {
        i = 29;
        while(i--);
    }
}

void GpioSetPinOut(GpioHandle *gpio)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = 1<<gpio->ch;	
    GPIO_Init(gpio_group[gpio->group], &GPIO_InitStructure);	
}

void GpioSetPinIn(GpioHandle *gpio)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Pin = 1<<gpio->ch;	
    GPIO_Init(gpio_group[gpio->group], &GPIO_InitStructure);
}
