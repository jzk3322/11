
#include "app_includes.h"

void power_out(uint8_t enable)
{
    if(enable)
    {
        GpioSetLow(&board.power_out.ce);
        GpioSetHigh(&board.power_out.enable);
    }
    else
    {
        GpioSetHigh(&board.power_out.ce);
        GpioSetLow(&board.power_out.enable);
    }
}

void power_set_voltage(uint16_t v)
{
    GeneralOutLevel level;
		DeviceParaStore *para = &device.para.store;
		if(v<para->load_v_offset)
			level = 0;
		else
			level = (GeneralOutLevel)((uint32_t)(v-para->load_v_offset)
							*board.power_out.voltage.levle_max/para->load_v_max);
    board.power_out.voltage.m->on(&board.power_out.voltage, level);
}

void power_set_current(uint16_t i)
{
    GeneralOutLevel level;
    level = (GeneralOutLevel)((uint32_t)i*board.power_out.current.levle_max/device.para.store.load_i_max);
    board.power_out.current.m->on(&board.power_out.current, level);
}
