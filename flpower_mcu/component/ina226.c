
#include "ina226.h"

status_t ina226_operate(INA226 *ina226, i2c_direction_t dir, uint8_t reg_addr, uint8_t *data, uint8_t len)
{
    ina226->transfer.subaddress = reg_addr;
    ina226->transfer.data = data;
    ina226->transfer.dataSize = len;
    ina226->transfer.direction = dir;
    return ina226_i2c_transfer(ina226->handle, &ina226->transfer);
}

void ina226_write_reg(INA226 *ina226, uint8_t reg_addr, uint16_t value)
{
    uint8_t reg_value[2];
    reg_value[0] = value>>8;
    reg_value[1] = value&0xff;
    ina226_operate(ina226, kI2C_Write, reg_addr, reg_value, 2);
}

uint16_t ina226_read_reg(INA226 *ina226, uint8_t reg_addr)
{
    volatile status_t result;
    uint8_t reg_value[2];
    result = ina226_operate(ina226, kI2C_Read, reg_addr, reg_value, 2);
    return (uint16_t)reg_value[0]<<8 | reg_value[1];
}

void ina226_init(INA226 *ina226, INA226_Init_Config_t *config)
{
    ina226->handle = config->handle;
    ina226->transfer.slaveAddress = config->slave_addr;
    ina226->transfer.subaddressSize = 1;
    
    ina226->id = ina226_read_reg(ina226, INA226_Reg_ID);
    
    ina226->config.value = 0x4000;
    ina226->config.avg = config->average;
    ina226->config.mode = config->mode;
    ina226->config.vbus_ct = config->bus_conversion_time;
    ina226->config.vshut_ct = config->shut_conversion_time;
    ina226_write_reg(ina226, INA226_Reg_Config, ina226->config.value);
}

/*
 * r_shut - 分流电阻
 * i_max - 最大采样电流
 * i_LSB = i_max/2^15
 * cal = 0.00512/(i_LSB * r_shut) = 0.00512*2^15/(i_max*r_shut)
 */
void ina226_set_calibrate(INA226 *ina226, float r_shut, float i_max)
{
    float cal;
    ina226->i_lsb = i_max/32768;
    ina226->v_lsb = 0.00125f;
    ina226->p_lsb = ina226->i_lsb*25;
    cal = 0.00512/(r_shut * ina226->i_lsb);
    ina226_write_reg(ina226, INA226_Reg_Calibration, (uint16_t)cal);
}

float ina226_get_voltage(INA226 *ina226)
{
    uint16_t value;
    value = ina226_read_reg(ina226, INA226_Reg_Bus);
    return ina226->v_lsb*value;
}

float ina226_get_current(INA226 *ina226)
{
    uint16_t value;
    value = ina226_read_reg(ina226, INA226_Reg_Current);
    return ina226->i_lsb*((int16_t)(value));
}

float ina226_get_power(INA226 *ina226)
{
    uint16_t value;
    value = ina226_read_reg(ina226, INA226_Reg_Power);
    return ina226->p_lsb*value;
}
