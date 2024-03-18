#include "app_includes.h"

void importBuffValue(DeviceMeter *meter, float value)
{
    
    uint16_t next_index = (meter->cnt+1)&(DEV_METER_BUFF_NUM-1);
	meter->valueTotal -= meter->valueBuff[next_index];
    meter->valueIns = value;
    meter->valueBuff[next_index] = meter->valueIns;
    meter->valueTotal += meter->valueBuff[next_index];
    meter->value = meter->valueTotal/DEV_METER_BUFF_NUM;
    meter->cnt = next_index;
    meter->inValid = 0;
}

void task_sample(void *para)
{
    
	uint16_t end_pos = 0;
    vTaskDelay(pdMS_TO_TICKS(2000));
    while(1)
    {
        if(xSemaphoreTake(xSemaphoreSample, portMAX_DELAY) == pdTRUE)
        {
            importBuffValue(&device.meter.powerVoltage, ina226_get_voltage(&board.ina226_power)*device.para.store.factor[0]);
            importBuffValue(&device.meter.powerCurrent, ina226_get_current(&board.ina226_power)*device.para.store.factor[1]);
            importBuffValue(&device.meter.powerPower, device.meter.powerVoltage.valueIns*device.meter.powerCurrent.valueIns);
            importBuffValue(&device.meter.loadVoltage, ina226_get_voltage(&board.ina226_load)*device.para.store.factor[2]);
            importBuffValue(&device.meter.loadCurrent, ina226_get_current(&board.ina226_load)*device.para.store.factor[3]);
            importBuffValue(&device.meter.loadPower, device.meter.loadVoltage.valueIns*device.meter.loadCurrent.valueIns);
				
            if((device.meter.loadCurrent.valueIns>0.05 && (device.meter.loadCurrent.valueIns+0.1)*1000>device.para.run.load_i_set)
                && (device.meter.loadVoltage.valueIns+0.1)*1000<device.para.run.load_v_set )
                deviceSignalInput(device.signal.cc_mode.id,1);
            else
                deviceSignalInput(device.signal.cc_mode.id,0);
        }
    }
}
