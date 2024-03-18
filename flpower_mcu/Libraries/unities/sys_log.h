/*
 * 声明模块相关参数，与资源包对应。
 * DeviceInfo结构体定义模块信息参数，
*/
#ifndef SYS_LOG_H
#define SYS_LOG_H

/* include freertos header files */
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"
#include "message_buffer.h"

#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>

#define SYSLOG_BUFFER_SIZE          (512)
#define SYSLOG_SRCDATA_SIZE         (64)

#define SYSLOG_WAIT_DEFAULT         (50) //默认等待时间mS

enum 
{
    SYSLog_system = 0,
    SYSLog_user1 = 1,
    SYSLog_user2 = 2,
    SYSLog_user3 = 3,
};

typedef struct
{
    MessageBufferHandle_t buffer;
    SemaphoreHandle_t lock;
    uint8_t init_flag;
    uint8_t level_mask; //日志等级屏蔽级
    char src_data[SYSLOG_SRCDATA_SIZE];
}sys_log_t;

extern sys_log_t sys_log;

extern void sys_log_init(uint8_t level);
extern size_t sys_log_get(char *recv_buffer, size_t recv_size, TickType_t wait);
extern void sys_log_add_ch_array(uint8_t level, const char *content, uint16_t len);
extern void sys_log_add_string(uint8_t level, const char *content);
extern void sys_log_printf(uint8_t level, const char *format, ...);
#endif

