
#ifndef DEVICE_H
#define DEVICE_H

#include "stdint.h"
#include "board.h"

#define DEV_METER_BUFF_NUM          (8)

#define SRC_TABLE_METER_ITEM_NUM		(7)
#define SRC_TABLE_SIGNAL_ITEM_NUM		(2)
#define SRC_TABLE_ITEM_NUM (SRC_TABLE_METER_ITEM_NUM+SRC_TABLE_SIGNAL_ITEM_NUM)

#define PARA_INFO_ITEM_NUM		(4)
#define PARA_STORE_ITEM_NUM		(7)
#define PARA_RUN_ITEM_NUM		(7)
#define PARA_ITEM_NUM   (PARA_INFO_ITEM_NUM+PARA_STORE_ITEM_NUM+PARA_RUN_ITEM_NUM)

#define PARA_RUN_ITEM_OFFSET    (PARA_INFO_ITEM_NUM+PARA_STORE_ITEM_NUM)
#pragma pack(1)

typedef struct
{   
    float valueIns; //
    float value;
    float valueBuff[DEV_METER_BUFF_NUM];
    float valueTotal;
    float valueOffset;
    float valueMax;
    float valueMin;
    int16_t sample;
    uint8_t id;
    uint8_t cnt;
    uint8_t mapOffset;
    int8_t pidOffset;
    uint8_t inValid;
}DeviceMeter;

typedef union
{
    struct
    {
        DeviceMeter loadCurrent; //
        DeviceMeter loadVoltage; //
        DeviceMeter loadPower; //
        DeviceMeter powerCurrent;
        DeviceMeter powerVoltage; //
        DeviceMeter powerPower; //
        DeviceMeter mcuTemp; //
    };
    DeviceMeter group[SRC_TABLE_METER_ITEM_NUM];
}DeviceMeterGroup;

typedef struct
{   
    uint8_t id;
    uint8_t ch; //
    uint8_t value:2;
    uint8_t valueLast:2;
    uint8_t change:1;
}DeviceSignal;

typedef union
{
    struct
    {
        DeviceSignal fault; //
				DeviceSignal cc_mode; //0-cv, 1-cc
    };
    DeviceSignal group[SRC_TABLE_SIGNAL_ITEM_NUM];
}DeviceSignalGroup;

/* 设备信息类参数 */
typedef struct
{
	char name[33]; //设备名称
	char os[28]; //操作系统，"freeRTOS10.2.0.1"
    char buildVersion[33]; //编译版本
	uint16_t svCRC; //软件校验码，156F
}DeviceParaInfo;
/* 设备存储类参数 */
typedef struct
{
    uint8_t pd_select_mode; //PD电源选择模式
    uint16_t load_v_max;
    uint16_t load_i_max;
    uint16_t load_v_offset;
    uint16_t load_i_offset;
		float factor[4];
}DeviceParaStore;
/* 设备运行类参数 */
typedef struct
{
    uint16_t load_v_set;
    uint16_t load_i_set;
    uint8_t load_enable;
}DeviceParaRun;
  
typedef struct
{
    DeviceParaInfo info;
    DeviceParaStore store;
    DeviceParaRun run;
}DevicePara;

#pragma pack()

typedef struct
{
    DeviceMeterGroup meter;
    DeviceSignalGroup signal;
    DevicePara para;
    //DeviceFactor factor;
    //const SrcTablePackage *srcTablePackage;
    //const ParaPackage *paraPackage;
}Device;

extern Device device;

extern void deviceInit(void);
extern void deviceSignalInput(uint8_t id, uint8_t value);
#endif
