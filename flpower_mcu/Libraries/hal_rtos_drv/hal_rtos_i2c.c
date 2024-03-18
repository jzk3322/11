#include "hal_rtos_i2c.h"

#define FLAG_TIMEOUT ((uint32_t)0x1000)
#define LONG_TIMEOUT ((uint32_t)(10 * FLAG_TIMEOUT))

volatile uint32_t timeout;

#define checkAck(base, ack, info, time) {\
    timeout = time; \
    while (!I2C_CheckEvent(base, ack)) \
	{ \
		if ((timeout--) == 0) \
        { \
            PRINTF(info); \
			return 1; \
        }\
	} \
}\
/*!
 * brief Performs the I2C transfer.
 *
 * This function performs the I2C transfer according to the data given in the transfer structure.
 *
 * param handle The RTOS I2C handle.
 * param transfer A structure specifying the transfer parameters.
 * return status of the operation.
 */
status_t I2C_RTOS_Transfer(i2c_rtos_handle_t *handle, i2c_master_transfer_t *transfer)
{
    uint32_t i;
    status_t status = 0;
    uint8_t ack;
    I2C_GenerateSTART(handle->base, 1);
    checkAck(handle->base, I2C_EVENT_MASTER_MODE_SELECT, "Slave send NACK for address\r\n", FLAG_TIMEOUT);
    I2C_Send7bitAddress(handle->base,(transfer->slaveAddress << 1),I2C_Direction_Transmitter);
    checkAck(handle->base, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED, "Slave send NACK for address\r\n", FLAG_TIMEOUT);
    I2C_SendData(handle->base, transfer->subaddress);
    checkAck(handle->base, I2C_EVENT_MASTER_BYTE_TRANSMITTED, "Slave send NACK for memory address\r\n", FLAG_TIMEOUT);
    if(transfer->direction==kI2C_Write)
    {
        for(i = 0; i < transfer->dataSize; i++)
		{
            
			I2C_SendData(handle->base, transfer->data[i]);
            checkAck(handle->base, I2C_EVENT_MASTER_BYTE_TRANSMITTED, "Slave send NACK for data\r\n", FLAG_TIMEOUT);
		}
        I2C_GenerateSTOP(handle->base, 1);
        for(i = 0; i < 1000000; i++) __NOP();
    }
    else
    {
        for(i = 0; i < SystemCoreClock/1000000; i++) __NOP();
        I2C_GenerateSTART(handle->base, 1);
        checkAck(handle->base, I2C_EVENT_MASTER_MODE_SELECT, "Slave send NACK for address\r\n", FLAG_TIMEOUT);
        I2C_Send7bitAddress(handle->base,(transfer->slaveAddress << 1),I2C_Direction_Receiver);
        checkAck(handle->base, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED, "Slave send NACK for address\r\n", FLAG_TIMEOUT);
        for(i = 0; i < transfer->dataSize-1; i++)
		{
            checkAck(handle->base, I2C_EVENT_MASTER_BYTE_RECEIVED, "Slave send NACK for address\r\n", FLAG_TIMEOUT); 
			transfer->data[i] = I2C_ReceiveData(handle->base);  
		}
        I2C_AcknowledgeConfig(handle->base, DISABLE);
        I2C_GenerateSTOP(handle->base, 1);
        checkAck(handle->base, I2C_EVENT_MASTER_BYTE_RECEIVED, "Slave send NACK for address\r\n", FLAG_TIMEOUT); 	
        transfer->data[i] = I2C_ReceiveData(handle->base);
        for(i = 0; i < SystemCoreClock/1000000; i++) __NOP();
        I2C_AcknowledgeConfig(handle->base, ENABLE);
    }
    return 0;
}