/*
 * INA226 功率监测芯片，可用于采集电压电流功率值, IIC接口
 * register 寄存器介绍:
 * 0x00 - Configuration Register, 配置寄存器, 用于设置转换时间、操作模式
 * 0x05 - Calibration Register, 校准寄存器, 
 */

#ifndef INA226_H
#define INA226_H

#include "bsp.h"

typedef i2c_simulate_handle_t ina226_handle_t;
#define ina226_i2c_transfer I2C_Simulate_Transfer
//typedef i2c_rtos_handle_t ina226_handle_t;
//#define ina226_i2c_transfer I2C_RTOS_Transfer

/* 寄存器地址 */
enum {
    INA226_Reg_Config = 0x00,  
    INA226_Reg_Shunt = 0x01,  
    INA226_Reg_Bus = 0x02,  
    INA226_Reg_Power = 0x03,  
    INA226_Reg_Current = 0x04,  
    INA226_Reg_Calibration = 0x05,  
    INA226_Reg_ID = 0xff,  
};

/* Averaging Mode */
enum {
    INA226_AVG_1  = 0,
    INA226_AVG_4  = 1,
    INA226_AVG_16 = 2,
    INA226_AVG_64 = 3,
    INA226_AVG_128  = 4,
    INA226_AVG_256  = 5,
    INA226_AVG_512  = 6,
    INA226_AVG_1024 = 7,
};

enum {
    INA226_CT_140us  = 0,
    INA226_CT_204us  = 1,
    INA226_CT_332us = 2,
    INA226_CT_588us = 3,
    INA226_CT_1100us  = 4,
    INA226_CT_2116us  = 5,
    INA226_CT_4156us  = 6,
    INA226_CT_8244us = 7,
};

enum {
    INA226_MODE_PowerDown1  = 0,
    INA226_MODE_ShunVlotageTriggered  = 1,
    INA226_MODE_BusVlotageTriggered = 2,
    INA226_MODE_ShunBusVlotageTriggered = 3,
    INA226_MODE_PowerDown2  = 4,
    INA226_MODE_ShunVlotageContinuous  = 5,
    INA226_MODE_BusVlotageContinuous  = 6,
    INA226_MODE_ShunBusVlotageContinuous = 7,
};

typedef union
{
    uint16_t value;
    struct 
    {
        uint16_t mode:3;
        uint16_t vshut_ct:3;
        uint16_t vbus_ct:3;
        uint16_t avg:3;
        uint16_t reserved:3;
        uint16_t rst:1;
    };
}INA226_reg_config_t;


typedef struct
{
    ina226_handle_t *handle;
    uint8_t slave_addr;
    uint8_t mode;
    uint8_t shut_conversion_time;
    uint8_t bus_conversion_time;
    uint8_t average;
}INA226_Init_Config_t;

typedef struct
{
    //i2c_rtos_handle_t *handle;
    ina226_handle_t *handle;
    i2c_master_transfer_t transfer;
    uint16_t id;
    INA226_reg_config_t config;
    float i_lsb;
    float v_lsb;
    float p_lsb;
}INA226;


extern void ina226_init(INA226 *ina226, INA226_Init_Config_t *config);
extern void ina226_set_calibrate(INA226 *ina226, float r_shut, float i_max);
extern float ina226_get_voltage(INA226 *ina226);
extern float ina226_get_current(INA226 *ina226);
extern float ina226_get_power(INA226 *ina226);
#endif
