/*
 * 声明模块相关参数，与资源包对应。
 * DeviceInfo结构体定义模块信息参数，
*/
#ifndef STRING_EXTEND_H
#define STRING_EXTEND_H

#include <string.h>
#include <stdint.h>


extern void arrcpy(char *t, const char *s, const char end);
extern uint32_t str_to_uint(const char *s);
extern uint8_t uint_to_str(char *s, unsigned long val, uint8_t point, uint8_t cnt, const char *unit);
extern uint8_t float_to_str(char *s, float val, unsigned char point, unsigned char cnt, const char *unit);
extern void hex_arr_to_str(char *s, uint8_t *array, uint16_t len);
#endif

