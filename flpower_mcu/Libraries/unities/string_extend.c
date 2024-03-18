/*******************************************************************************
* Copyright (C) 2023 TOMATO.ltd
* @file      app_init.c
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
#include "string_extend.h"

void arrcpy(char *t, const char *s, const char end)
{
    uint16_t i = 0;
    while(*s!=end)
    {
        t[i++] = *s++;
    }
    t[i] = '\0';
}

uint32_t str_to_uint(const char *s)
{
    uint32_t v = 0;
    while (*s >= '0' && *s <= '9')
    {
        v = v * 10 + (*s - '0');
        s++;
    }
    return v;    
}

/*
 *
 * return 字符串长度
 */
uint8_t uint_to_str(char *s, unsigned long val, uint8_t point, uint8_t cnt, const char *unit)
{
    char s1[] = "000000000000000000000000000000";
    uint8_t i = 0, j, len;
    uint8_t unitLen = 0;
    if(unit!=NULL)
    {
        unitLen = strlen(unit);
        for (j = unitLen; j > 0; j--)
        {
            s1[j - 1] = *unit; // 存单位
            unit++;
            i++;
        }
    }
    do
    { // i = 字符串长度
        s1[i++] = val % 10 + 0x30;
        //if((i-unitLen)==point)
        if ((i - unitLen) == point)
            s1[i++] = '.';
        val /= 10;
    } while ((val != 0 || i - unitLen < point) && (i < 15)); // 获得反向字符串
    if (point != 0 && (i - unitLen - 1) == point)            // .0A的情况
        i++;                                                 // 0.0A
    if (i < cnt)
        i = cnt;
    len = i;
    while (i != 0)
    {
        *(s++) = s1[(i--) - 1];
    }
    *s = '\0';
    return len; 
}
uint8_t int_to_str(char *s, unsigned long val, unsigned char point, unsigned char cnt, const char *unit)
{
    char s1[] = "000000000000000000000000000000";
    uint8_t i = 0, j, len;
    uint8_t unitLen = 0;
    if(unit!=NULL)
        unitLen = strlen(unit);
    for (j = unitLen; j > 0; j--)
    {
        s1[j - 1] = *unit; // ´浥λ
        unit++;
        i++;
    }
    do
    { // i = ז·û´®³¤¶ȍ
        s1[i++] = val % 10 + 0x30;
        //if((i-unitLen)==point)
        if ((i - unitLen) == point)
            s1[i++] = '.';
        val /= 10;
    } while ((val != 0 || i - unitLen < point) && (i < 15)); // »񵃷´ϲז·û´®
    if (point != 0 && (i - unitLen - 1) == point)            // .0Aµć鿶
        i++;                                                 // 0.0A
    if (i < cnt)
        i = cnt;
    len = i;
    while (i != 0)
    {
        *(s++) = s1[(i--) - 1];
    }
    *s = '\0';
    return len;
}

uint8_t int_to_str_sign(char *s, long long val, unsigned char point, unsigned char cnt, const char *unit)
{
    if (val < 0)
    {
        val = (~val) + 1;
        *(s++) = '-';
    }
    return int_to_str(s, val, point, cnt, unit);
}

uint8_t float_to_str(char *s, float val, unsigned char point, unsigned char cnt, const char *unit)
{
	uint32_t factor[] = {1,10,100,1000,10000,100000};
	if(point>5)
		point = 5;
	int32_t int_val = (int32_t)(val*factor[point]);
	return int_to_str_sign(s, int_val, point, cnt, unit);
}
char hex_to_char(uint8_t hex)
{
    hex &= 0x0f;
    if (hex <= 9)
        return hex + '0';
    else
        return hex - 10 + 'A';
}

/*
 * uint8_t的hex值转成字符
 * 注意使用后字符串结尾需要手动添加'\0'
*/
void hex8_to_str(char *s, uint8_t hex)
{
    *s++ = hex_to_char(hex >> 4);
    *s = hex_to_char(hex);
}

void hex_arr_to_str(char *s, uint8_t *array, uint16_t len)
{
    uint16_t i;
    for(i=0;i!=len; i++)
    {
        hex8_to_str(s, array[i]);
        s += 2;
    }
    *s = '\0';
}
