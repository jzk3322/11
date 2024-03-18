// 基于RTOS的硬件抽象驱动库
// author zf
// date 2023/09/14 
#ifndef HAL_RTOS_I2C_H
#define HAL_RTOS_I2C_H

#include "stdint.h"
#include <string.h>
#include "hal_rtos_drv.h"

/*! @brief I2C transfer control flag. */
enum _i2c_master_transfer_flags
{
    kI2C_TransferDefaultFlag = 0x0U,       /*!< A transfer starts with a start signal, stops with a stop signal. */
    kI2C_TransferNoStartFlag = 0x1U,       /*!< A transfer starts without a start signal, only support write only or
                                        write+read with no start flag, do not support read only with no start flag. */
    kI2C_TransferRepeatedStartFlag = 0x2U, /*!< A transfer starts with a repeated start signal. */
    kI2C_TransferNoStopFlag        = 0x4U, /*!< A transfer ends without a stop signal. */
};
/*! @brief The direction of master and slave transfers. */
typedef enum _i2c_direction
{
    kI2C_Write = 0x0U, /*!< Master transmits to the slave. */
    kI2C_Read  = 0x1U, /*!< Master receives from the slave. */
} i2c_direction_t;

typedef struct _i2c_master_transfer
{
    uint32_t flags;            /*!< A transfer flag which controls the transfer. */
    uint8_t slaveAddress;      /*!< 7-bit slave address. */
    i2c_direction_t direction; /*!< A transfer direction, read or write. */
    uint32_t subaddress;       /*!< A sub address. Transferred MSB first. */
    uint8_t subaddressSize;    /*!< A size of the command buffer. */
    uint8_t *volatile data;    /*!< A transfer buffer. */
    volatile size_t dataSize;  /*!< A transfer size. */
} i2c_master_transfer_t;

/*!
 * @cond RTOS_PRIVATE
 * @brief I2C FreeRTOS handle
 */
typedef struct _i2c_rtos_handle
{
    I2C_TypeDef *base;                 /*!< I2C base address */    
    //i2c_master_handle_t drv_handle; /*!< A handle of the underlying driver, treated as opaque by the RTOS layer */
    //status_t async_status;          /*!< Transactional state of the underlying driver */
    SemaphoreHandle_t mutex;        /*!< A mutex to lock the handle during a transfer */
    SemaphoreHandle_t semaphore;    /*!< A semaphore to notify and unblock task when the transfer ends */
#if (configSUPPORT_STATIC_ALLOCATION == 1)
    StaticSemaphore_t mutexBuffer;     /*!< Statically allocated memory for mutex */
    StaticSemaphore_t semaphoreBuffer; /*!< Statically allocated memory for semaphore */
#endif
} i2c_rtos_handle_t;

extern status_t I2C_RTOS_Transfer(i2c_rtos_handle_t *handle, i2c_master_transfer_t *transfer);
#endif
