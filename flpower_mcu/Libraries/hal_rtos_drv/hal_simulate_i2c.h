// 基于RTOS的硬件抽象驱动库
// author zf
// date 2023/09/14 
#ifndef HAL_SIMULATE_I2C_H
#define HAL_SIMULATE_I2C_H

#include "stdint.h"
#include <string.h>
#include "hal_rtos_i2c.h"

/*!
 * @cond RTOS_PRIVATE
 * @brief I2C FreeRTOS handle
 */
typedef struct _i2c_simulate_handle
{
    GpioHandle *scl;
    GpioHandle *sda;
    uint32_t freq;
} i2c_simulate_handle_t;

extern status_t I2C_Simulate_Transfer(i2c_simulate_handle_t *handle, i2c_master_transfer_t *transfer);
extern void I2C_Simulate_init(i2c_simulate_handle_t *handle, GpioHandle *scl, GpioHandle *sda, uint32_t freq);
#endif
