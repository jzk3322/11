
#include "board.h"

Board board;


//static i2c_rtos_handle_t i2c_fusb302;
static i2c_simulate_handle_t i2c_fusb302;
static i2c_master_transfer_t i2c_fusb302_transfer;
/* fusb302 i2c接口 */
FUSB302_ret_t fusb302_i2c_read(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data, uint8_t len)
{
    status_t result;
    i2c_fusb302_transfer.subaddress = reg_addr;
    i2c_fusb302_transfer.data = data;
    i2c_fusb302_transfer.dataSize = len;
    i2c_fusb302_transfer.direction = kI2C_Read;
    i2c_fusb302_transfer.slaveAddress = dev_addr;
    i2c_fusb302_transfer.subaddressSize = 1;
    result = I2C_Simulate_Transfer(&i2c_fusb302, &i2c_fusb302_transfer);
    return result == 0 ? FUSB302_SUCCESS : FUSB302_ERR_READ_DEVICE;
}
FUSB302_ret_t fusb302_i2c_write(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data, uint8_t len)
{
    status_t result;
    i2c_fusb302_transfer.subaddress = reg_addr;
    i2c_fusb302_transfer.data = data;
    i2c_fusb302_transfer.dataSize = len;
    i2c_fusb302_transfer.direction = kI2C_Write;
    i2c_fusb302_transfer.slaveAddress = dev_addr;
    i2c_fusb302_transfer.subaddressSize = 1;
    result = I2C_Simulate_Transfer(&i2c_fusb302, &i2c_fusb302_transfer);
    return result == 0 ? FUSB302_SUCCESS : FUSB302_ERR_READ_DEVICE;
}

FUSB302_ret_t fusb302_delay_ms(uint32_t t)
{
    HalDelayMs(t);
    return FUSB302_SUCCESS;
}

void board_init(void)
{
    
	sys_log_init(0);
    board.power_out.ce.port = HalPort(1, 5); //PB5
    board.power_out.enable.port = HalPort(0, 2); //PA2
    static PwmHandle power_out_voltage_handle;
    static PwmHandle power_out_current_handle;
    power_out_current_handle.port = HalPort(4, 1); //TIM4_CH1
    power_out_voltage_handle.port = HalPort(4, 2); //TIM4_CH2
    PwmGeneralOutInit(&board.power_out.voltage, &power_out_voltage_handle, 0, 40000, 1000);
    PwmGeneralOutInit(&board.power_out.current, &power_out_current_handle, 0, 40000, 1000);
    /* LED */
    static PwmHandle led_run_handle;
    led_run_handle.port = HalPort(3, 2); //TIM3_CH2
    PwmLedInit(&board.led_run, &led_run_handle, 1, 10000, 10000);
 
    /* Key group */
    static GpioHandle switch_left_handle; 
    switch_left_handle.port = HalPort(0, 1); //PA1   
    GpioKeyInit(&board.switch_group.left, &switch_left_handle, 1);
    static GpioHandle switch_right_handle; 
    switch_right_handle.port = HalPort(2, 13); //PC13   
    GpioKeyInit(&board.switch_group.right, &switch_right_handle, 1);
    static GpioHandle switch_power_handle; 
    switch_power_handle.port = HalPort(1, 3); //PB3   
    GpioKeyInit(&board.switch_group.power, &switch_power_handle, 0);
    /* encoder */
    static GpioEncoderHandle encoder_handle;
    encoder_handle.k.port = HalPort(2, 15); //PC15
    encoder_handle.b.port = HalPort(0, 0); //PA0
    encoder_handle.a.port = HalPort(2, 14); //PC14
    GpioEncoderInit(&board.encoder, &encoder_handle);
    
    board.fusb302_int_gpio_handle.port = HalPort(1, 0);
    /*    
    i2c_fusb302.base = I2C2;
    */
    static GpioHandle i2c_fusb302_scl, i2c_fusb302_sda;
    i2c_fusb302_scl.port = HalPort(1, 10); //PB10   
    i2c_fusb302_sda.port = HalPort(1, 11); //PB11   
    I2C_Simulate_init(&i2c_fusb302, &i2c_fusb302_scl, &i2c_fusb302_sda, 100000);
    board.fusb302.i2c_address = 0x22;
    board.fusb302.i2c_read = fusb302_i2c_read;
    board.fusb302.i2c_write = fusb302_i2c_write;
    board.fusb302.delay_ms = fusb302_delay_ms;
    
    static i2c_simulate_handle_t i2c_ina226;
    static GpioHandle i2c_ina226_scl, i2c_ina226_sda;
    i2c_ina226_scl.port = HalPort(1, 8); //PB8   
    i2c_ina226_sda.port = HalPort(1, 9); //PB9   
    I2C_Simulate_init(&i2c_ina226, &i2c_ina226_scl, &i2c_ina226_sda, 100000);
    /*
    static i2c_rtos_handle_t i2c_ina226;
    i2c_ina226.base = I2C1;
    */
    INA226_Init_Config_t ina226_config;
    ina226_config.handle = &i2c_ina226;
    ina226_config.slave_addr = 0x45;
    ina226_config.average = INA226_AVG_16;
    ina226_config.mode = INA226_MODE_ShunBusVlotageContinuous;
    ina226_config.bus_conversion_time = INA226_CT_1100us;
    ina226_config.shut_conversion_time = INA226_CT_1100us;
    ina226_init(&board.ina226_power, &ina226_config);
    sys_log_printf(SYSLog_system, "POWER INA226 initialized, id:%d\r", board.ina226_power.id);
    ina226_set_calibrate(&board.ina226_power,0.01, 6);
    
    ina226_config.slave_addr = 0x40;
    ina226_init(&board.ina226_load, &ina226_config);
    sys_log_printf(SYSLog_system, "LOAD INA226 initialized, id:%d\r", board.ina226_power.id);
    ina226_set_calibrate(&board.ina226_load,0.01, 6);
}

/* 定时扫描开关按键组 */
uint8_t BoardSwitchGroupScan(uint16_t ms)
{
    //static BaseType_t xHigherPriorityTaskWoken;
    uint8_t change = 0;
    change |= KeyScan(&board.switch_group.left, board.switch_group.debounce_time, ms);
    change |= KeyScan(&board.switch_group.right, board.switch_group.debounce_time, ms);
    change |= KeyScan(&board.switch_group.power, board.switch_group.debounce_time, ms);
    change = GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_1);
    if(change)
    {
        ;//xSemaphoreGiveFromISR(board.switch_group.event_change,&xHigherPriorityTaskWoken);
    }
    return change;
}

/* 定时节拍任务函数，在定时中断中执行 */
void BoardTimerTask(uint16_t ms)
{
    BoardSwitchGroupScan(ms);
    EncoderScan(&board.encoder, 20, ms);
}

int board_serial_send(uint8_t id, const char *buffer, uint32_t length)
{
    uint32_t i;
    for(i=0;i!=length;i++)
    {
        while (!USART_GetFlagStatus(USART1, USART_FLAG_TC))
            ;
        USART_SendData(USART1, (uint8_t)buffer[i]);
    }
	return kStatus_Success;
}

int SER_PutChar (int ch)
{
	while(!USART_GetFlagStatus(USART1,USART_FLAG_TC));
	USART_SendData(USART1, (uint8_t) ch);

	return ch;
}

int fputc(int c, FILE *f)
{
	/* Place your implementation of fputc here */
	/* e.g. write a character to the USART */
	if (c == '\n')
	{
		SER_PutChar('\r');
	}
	return (SER_PutChar(c));
}