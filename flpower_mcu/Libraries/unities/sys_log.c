/*******************************************************************************
* Copyright (C) 2023 TOMATO.ltd
* @file      sys_log.c
* @author    zhang
* @version   1.0.0.1
* @date      2023/12/2
* @brief     
* details.
* 
* change history
* <date>      | <version>   | <author>      | <description>
* 2023/12/2   | 1.0.0.1     | zhang         | create file
*
*******************************************************************************/
#include "sys_log.h"

sys_log_t sys_log;

void sys_log_init(uint8_t level)
{
    sys_log.level_mask = level;
    sys_log.buffer = xMessageBufferCreate(SYSLOG_BUFFER_SIZE);
    sys_log.lock = xSemaphoreCreateMutex();
    sys_log.init_flag = 1;
}

/* 获取日志 */
size_t sys_log_get(char *recv_buffer, size_t recv_size, TickType_t wait)
{
    if(!sys_log.init_flag)
        return 0;
    return xMessageBufferReceive(sys_log.buffer, recv_buffer, recv_size, wait);
}

/* 添字符数组日志 */
void sys_log_add_ch_array(uint8_t level, const char *content, uint16_t len)
{
    if(!sys_log.init_flag || level<sys_log.level_mask)
        return;
    if(len>SYSLOG_SRCDATA_SIZE)
        len = SYSLOG_SRCDATA_SIZE;
    if(xSemaphoreTake(sys_log.lock, SYSLOG_WAIT_DEFAULT)==pdTRUE)
    {
        xMessageBufferSend(sys_log.buffer, content, len, SYSLOG_WAIT_DEFAULT);
        xSemaphoreGive(sys_log.lock);
    }
}

/* 添字符串日志 */
void sys_log_add_string(uint8_t level, const char *content)
{
    sys_log_add_ch_array(level, content, strlen(content));
}

void sys_log_printf(uint8_t level, const char *format, ...)
{
    va_list args;
	va_start(args, format);
	vsprintf(sys_log.src_data, format, args);
	va_end(args);
    sys_log_add_string(level, sys_log.src_data);
}
