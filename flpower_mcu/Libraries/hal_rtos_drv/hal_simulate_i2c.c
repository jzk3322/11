#include "hal_simulate_i2c.h"

#define DELAY_US    5

void simulate_i2c_start(i2c_simulate_handle_t *handle)
{
    GpioSetHigh(handle->sda);
    GpioSetHigh(handle->scl);
    hal_delay_us_block(DELAY_US);
    GpioSetLow(handle->sda);
    hal_delay_us_block(DELAY_US);
    GpioSetLow(handle->scl);
    hal_delay_us_block(DELAY_US);
}

void simulate_i2c_stop(i2c_simulate_handle_t *handle)
{
    GpioSetLow(handle->sda);
    GpioSetHigh(handle->scl);
    hal_delay_us_block(DELAY_US);
    GpioSetHigh(handle->sda);
}

void simulate_i2c_ack(i2c_simulate_handle_t *handle)
{
    GpioSetLow(handle->sda);
    hal_delay_us_block(DELAY_US);
    GpioSetHigh(handle->scl);
    hal_delay_us_block(DELAY_US);
    GpioSetLow(handle->scl);
    hal_delay_us_block(DELAY_US);
    GpioSetHigh(handle->sda);
}

void simulate_i2c_nack(i2c_simulate_handle_t *handle)
{
    GpioSetHigh(handle->sda);
    hal_delay_us_block(DELAY_US);
    GpioSetHigh(handle->scl);
    hal_delay_us_block(DELAY_US);
    GpioSetLow(handle->scl);
    hal_delay_us_block(DELAY_US);
}

uint8_t simulate_i2c_check_ack_err(i2c_simulate_handle_t *handle)
{
    uint32_t time = 0;
    GpioSetHigh(handle->sda);
    hal_delay_us_block(DELAY_US);
    GpioSetHigh(handle->scl);
    hal_delay_us_block(DELAY_US);
    //GpioSetPinIn(handle->sda);
    while(GpioGetValue(handle->sda))
    {
        time++;
        if(time>=100)
        {
            simulate_i2c_stop(handle);
            return 1;
        }
    }
    //GpioSetPinOut(handle->sda);
    GpioSetLow(handle->scl);
    hal_delay_us_block(DELAY_US);
    return 0;
}

void simulate_i2c_send_data(i2c_simulate_handle_t *handle, uint8_t data)
{
    uint8_t i;
    GpioSetLow(handle->scl);
    for(i=0;i!=8;i++)
    {
        GpioSetValue(handle->sda, (data>>(7-i))&0x01);
        hal_delay_us_block(DELAY_US);
        GpioSetHigh(handle->scl);
        hal_delay_us_block(DELAY_US);
        GpioSetLow(handle->scl);
        hal_delay_us_block(DELAY_US);
    }
    GpioSetHigh(handle->sda);
}

uint8_t simulate_i2c_read_data(i2c_simulate_handle_t *handle, uint8_t ack)
{
    uint8_t i, data = 0;
    //GpioSetPinIn(handle->sda);
    for(i=0;i!=8;i++)
    {
        data <<= 1;
        GpioSetHigh(handle->scl);
        hal_delay_us_block(DELAY_US);
        data |= GpioGetValue(handle->sda);
        GpioSetLow(handle->scl);
        hal_delay_us_block(DELAY_US);
    }
    //GpioSetPinOut(handle->sda);
    if(ack)
        simulate_i2c_ack(handle);
    else
        simulate_i2c_nack(handle);
    return data;
}

status_t I2C_Simulate_Transfer(i2c_simulate_handle_t *handle, i2c_master_transfer_t *transfer)
{
    uint32_t i;
    uint8_t ack;
    simulate_i2c_start(handle);
    simulate_i2c_send_data(handle, (transfer->slaveAddress << 1)); //发送从地址写
    if(simulate_i2c_check_ack_err(handle)) return 1;
    simulate_i2c_send_data(handle, transfer->subaddress); //发送寄存器地址
    if(simulate_i2c_check_ack_err(handle)) return 1;
    if(transfer->direction==kI2C_Write)
    {
        for(i = 0; i < transfer->dataSize; i++)
		{
            
			simulate_i2c_send_data(handle, transfer->data[i]);
            if(simulate_i2c_check_ack_err(handle)) return 1;
		}
        simulate_i2c_stop(handle);
        hal_delay_us_block(2000);
    }
    else
    {
        simulate_i2c_start(handle);
        simulate_i2c_send_data(handle, (transfer->slaveAddress << 1)|0x01); //发送从地址读
        if(simulate_i2c_check_ack_err(handle)) return 1;
        for(i = 0; i < transfer->dataSize-1; i++)
		{
			transfer->data[i] = simulate_i2c_read_data(handle, 1);
		}
        transfer->data[i] = simulate_i2c_read_data(handle, 0);
        simulate_i2c_stop(handle);        
    }
    return 0;
}


void I2C_Simulate_init(i2c_simulate_handle_t *handle, GpioHandle *scl, GpioHandle *sda, uint32_t freq)
{
    handle->freq = freq;
    handle->scl = scl;
    handle->sda = sda;
}

