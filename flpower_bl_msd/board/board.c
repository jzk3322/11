
#include "board.h"

board_t board;


void RCC_ClkConfiguration(void)
{
	RCC_DeInit(); //复位RCC寄存器

	RCC_HSEConfig(RCC_HSE_ON); //使能HSE
	while (RCC_GetFlagStatus(RCC_FLAG_HSERDY) == RESET)
		; //等待HSE就绪

	RCC_PLLCmd(DISABLE);										 //关闭PLL
	AIR_RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_27, FLASH_Div_2); //配置PLL,8*27=216MHz

	RCC_PLLCmd(ENABLE); //使能PLL
	while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
		; //等待PLL就绪

	RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK); //选择PLL作为系统时钟

	RCC_HCLKConfig(RCC_SYSCLK_Div1); //配置AHB时钟
	RCC_PCLK1Config(RCC_HCLK_Div2);	 //配置APB1时钟
	RCC_PCLK2Config(RCC_HCLK_Div1);	 //配置APB2时钟

	RCC_LSICmd(ENABLE); //使能内部低速时钟
	while (RCC_GetFlagStatus(RCC_FLAG_LSIRDY) == RESET)
		;				//等待LSI就绪
	RCC_HSICmd(ENABLE); //使能内部高速时钟
	while (RCC_GetFlagStatus(RCC_FLAG_HSIRDY) == RESET)
		; //等待HSI就绪
}

void board_io_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;	
	GPIO_Init(GPIOA, &GPIO_InitStructure);    
}

void board_init(void)
{
    RCC_ClocksTypeDef clocks;
    
    RCC_ClkConfiguration();
    
	RCC_GetClocksFreq(&clocks);
	PRINTF_LOG("\n");
	PRINTF_LOG("SYSCLK: %3.1fMhz, HCLK: %3.1fMhz, PCLK1: %3.1fMhz, PCLK2: %3.1fMhz, ADCCLK: %3.1fMhz\n", \
	(float)clocks.SYSCLK_Frequency/1000000, (float)clocks.HCLK_Frequency/1000000, \
	(float)clocks.PCLK1_Frequency/1000000, (float)clocks.PCLK2_Frequency / 1000000, (float)clocks.ADCCLK_Frequency / 1000000);

    board_io_init();
    
	UART_Configuration(115200);  
    
    board.ap_address = 0x08004000; //定义应用程序起始地址
    board.flash_size = (*(volatile uint16_t *) 0x1FFFF7E0)*1024; //获取mcu容量，单位Byte
    board.page_size = 2048;
    board.ap_size = board.flash_size - (board.ap_address-NVIC_VectTab_FLASH);
    
	Delay_Init();
	
	Set_System();
	Delay_Ms(1500);
}

void board_usb_config(void)
{
    
	USB_Port_Set(0); 	//USB先断开
	Delay_Ms(700);
	USB_Port_Set(1);	//USB再次连接 
    
	Set_USBClock();
	USB_Interrupts_Config();
	USB_Init();
	DP_PUUP = 1; //DP引脚设置内部上拉电阻
}
    

uint8_t board_key_press(void)
{
    return !PAin(1);
}

int board_jump_to_app(void)
{
    static __IO uint32_t s_stackPointer = 0;
	s_stackPointer = *(uint32_t *)board.ap_address;
	static void (*farewellBootloader)(void) = 0;
    __set_FAULTMASK(1);
    if (((*(__IO uint32_t*)board.ap_address) & 0x2FFE0000 ) == 0x20000000) 
    {  
        farewellBootloader = (void (*)(void))(*(uint32_t*)(board.ap_address + 4));
        __set_MSP(s_stackPointer);  
        __set_CONTROL(0);  
        SCB->VTOR = board.ap_address;
        farewellBootloader();
        return 1;
    } 
    return 0;
}