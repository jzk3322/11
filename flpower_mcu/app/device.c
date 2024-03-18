#include "app_includes.h"

Device device;

//void deviceRefreshMeter(void)
//{
//    ;//device.meter.solderTemp = solder.tempCurrent/100.0;
//}

void deviceInfoInit(void)
{
    memset(&device.para.info,0,sizeof(device.para.info));
    strcpy(device.para.info.name,"FL POWER V1");
    strcpy(device.para.info.os,"freeRTOS10.2.0.1");
    strcpy(device.para.info.buildVersion,BUILD_VERSION);
}

void deviceInit(void)
{
    uint16_t i;
    
    deviceInfoInit();
    for(i=0;i!=SRC_TABLE_METER_ITEM_NUM;i++)
    {
        device.meter.group[i].id = i;
    }
    for(i=0;i!=SRC_TABLE_SIGNAL_ITEM_NUM;i++)
    {
        device.signal.group[i].id = i;
    }
    
    //I_OUT_LIM = (1.21V/RILIM2)*(RSS2/RSNS2)
    device.para.store.load_i_max = (1.21/24000)*(1000/0.01)*1000;
    device.para.store.load_v_max = 30.2*1000;
		device.para.store.load_v_offset = 0.39*1000; //
		device.para.store.factor[0] = 1;
		device.para.store.factor[1] = 1;
		device.para.store.factor[2] = 0.9945;
		device.para.store.factor[3] = 1;
		
    device.para.run.load_v_set = 5000;
    device.para.run.load_i_set = 2000;
}

void deviceSignalInput(uint8_t id, uint8_t value)
{
    device.signal.group[id].valueLast = device.signal.group[id].value;
    device.signal.group[id].value = value;
    if(device.signal.group[id].valueLast!=device.signal.group[id].value)
        device.signal.group[id].change = 1;
}