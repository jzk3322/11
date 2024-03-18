
#include "bsp.h"

void UART_Configuration(uint32_t bound)
{
	USART_InitTypeDef USART_InitStructure;

	USART_InitStructure.USART_BaudRate = bound;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	USART_Init(USART1, &USART_InitStructure);
	USART_Cmd(USART1, ENABLE);
}

/* 初始化IO */
static void bsp_io_init(void)
{
    GPIO_InitTypeDef init_config;
	init_config.GPIO_Speed = GPIO_Speed_50MHz;
    
    /* UART1, PA9[TX], PA10[RX] */
	init_config.GPIO_Mode = GPIO_Mode_AF_PP;
	init_config.GPIO_Pin = GPIO_Pin_9;
	GPIO_Init(GPIOA, &init_config);
	init_config.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	init_config.GPIO_Pin = GPIO_Pin_10;
	GPIO_Init(GPIOA, &init_config);
    
    // LCD_BL TIM1_CH1, PA8
	init_config.GPIO_Pin = GPIO_Pin_8;		  
	//init_config.GPIO_Mode = GPIO_Mode_AF_PP;
    init_config.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &init_config);	
    
    // PWM PWR_I TIM4_CH1-PB6 |  PWR_U TIM4_CH1-PB7
	init_config.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;		  
	init_config.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOB, &init_config);	
    
    // I2C1 PB8 PB9
	init_config.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9;	  
	init_config.GPIO_Mode = GPIO_Mode_Out_OD;		  
	//init_config.GPIO_Mode = GPIO_Mode_AF_OD;
	GPIO_Init(GPIOB, &init_config);	
    // I2C2 PB10 PB11
	init_config.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_11;	  
	init_config.GPIO_Mode = GPIO_Mode_Out_OD;		  
	//init_config.GPIO_Mode = GPIO_Mode_AF_OD;
	GPIO_Init(GPIOB, &init_config);	
    
    // SPI2, SCK-PB13, MOSI-PB15
	init_config.GPIO_Mode = GPIO_Mode_AF_PP;
    //init_config.GPIO_Mode = GPIO_Mode_Out_PP;
    init_config.GPIO_Pin = GPIO_Pin_13|GPIO_Pin_15;
	GPIO_Init(GPIOB, &init_config);
    
    // LCD, CS-PB12, DC-PB14, RST-PA15
	init_config.GPIO_Mode = GPIO_Mode_Out_PP;
    init_config.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_14;
	GPIO_Init(GPIOB, &init_config);
	init_config.GPIO_Mode = GPIO_Mode_Out_PP;
    init_config.GPIO_Pin = GPIO_Pin_15;
	GPIO_Init(GPIOA, &init_config);
    
    /* LED, PA7 TIM3_CH2*/
	//init_config.GPIO_Mode = GPIO_Mode_Out_PP;
	init_config.GPIO_Mode = GPIO_Mode_AF_PP;
	init_config.GPIO_Pin = GPIO_Pin_7;
    GPIO_Init(GPIOA, &init_config);
    
    // Encoder, a-PA0, b-PC14, k-PC15
    // KEY, left-PA1, right-PC13 , power-PB3
    init_config.GPIO_Mode = GPIO_Mode_IPU;
    init_config.GPIO_Pin = GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
    GPIO_Init(GPIOC, &init_config);
    init_config.GPIO_Mode = GPIO_Mode_IPU;
    init_config.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;
    GPIO_Init(GPIOA, &init_config);
    init_config.GPIO_Mode = GPIO_Mode_IPU;
    init_config.GPIO_Pin = GPIO_Pin_3;
    GPIO_Init(GPIOB, &init_config);
    //fusb302 INT
    init_config.GPIO_Mode = GPIO_Mode_IPU;
    init_config.GPIO_Pin = GPIO_Pin_0;
    GPIO_Init(GPIOB, &init_config);
    //power enable-PA2, CE-PB5, 
	init_config.GPIO_Mode = GPIO_Mode_Out_PP;
    init_config.GPIO_Pin = GPIO_Pin_2;
	GPIO_Init(GPIOA, &init_config);
    init_config.GPIO_Pin = GPIO_Pin_5;
	GPIO_Init(GPIOB, &init_config);
    
	GPIO_ForcePuPdCmd(GPIOB, ENABLE);		   //开启内部上拉
	GPIO_ForcePullUpConfig(GPIOB, GPIO_Pin_9); // PB9上拉
    
    PWR_BackupAccessCmd(DISABLE);/* 禁止修改RTC和后备寄存器*/
}

static void bsp_timer1_init(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_TimeBaseStructure.TIM_Prescaler = 0;					// 预分频器
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; // 向上计数模式
	TIM_TimeBaseStructure.TIM_Period = (SystemCoreClock / 16000) - 1;				// 自动重装载值，定时器周期为17570Hz
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;				// 时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 2;			// 重复计数器
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); // 初始化定时器1
    
    TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;				// 选择定时器模式:TIM脉冲宽度调制模式2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	// 比较输出使能
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable; // 互补输出使能
	TIM_OCInitStructure.TIM_Pulse = 1000;					            // 设置待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;		// 输出极性:TIM输出比较极性低
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;		// 空闲状态下的输出电平

	TIM_OC1Init(TIM1, &TIM_OCInitStructure); // 初始化TIM1 Channel1 PWM模式
	TIM_Cmd(TIM1, ENABLE); // 使能TIM1
	TIM_CtrlPWMOutputs(TIM1, ENABLE); // MOE 主输出使能
}

static void bsp_timer4_init(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_TimeBaseStructure.TIM_Prescaler = 0;					// 预分频器
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; // 向上计数模式
	TIM_TimeBaseStructure.TIM_Period = BSP_PWR_PWM_PERIOD - 1; // 自动重装载值，定时器周期为256M/BSP_PWR_PWM_PERIOD
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;				// 时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 2;			// 重复计数器
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); // 初始化定时器1
    
    TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;				// 选择定时器模式:TIM脉冲宽度调制模式1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	// 比较输出使能
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable; // 互补输出使能
	TIM_OCInitStructure.TIM_Pulse = BSP_PWR_PWM_PERIOD/2;		     // 设置待装入捕获比较寄存器的脉冲值
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;		// 输出极性:TIM输出比较极性低
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;		// 空闲状态下的输出电平

	TIM_OC1Init(TIM4, &TIM_OCInitStructure); // 初始化TIM1 Channel1 PWM模式
	TIM_OC2Init(TIM4, &TIM_OCInitStructure); // 初始化TIM1 Channel2 PWM模式
	TIM_Cmd(TIM4, ENABLE); // 使能TIM1
}

static void bsp_timer3_init(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_TimeBaseStructure.TIM_Prescaler = 0;					// 预分频器
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; // 向上计数模式
	TIM_TimeBaseStructure.TIM_Period = (SystemCoreClock / 16000) - 1; // 自动重装载值
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;				// 时钟分割:TDTS = Tck_tim
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); // 初始化定时器1
    
    TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;				// 选择定时器模式:TIM脉冲宽度调制模式1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	// 比较输出使能
	TIM_OCInitStructure.TIM_Pulse = (SystemCoreClock / 16000)/2;		     // 设置待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;		// 输出极性:TIM输出比较极性低
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;		// 空闲状态下的输出电平

	TIM_OC2Init(TIM3, &TIM_OCInitStructure); // 初始化TIM3 Channel2 PWM模式
	TIM_CtrlPWMOutputs(TIM3, ENABLE); // MOE 主输出使能
    TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable); 
    TIM_ARRPreloadConfig(TIM3, ENABLE);
	TIM_Cmd(TIM3, ENABLE); // 使能TIM3
}

static void bsp_timer2_init(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_ClocksTypeDef clocks;
	RCC_GetClocksFreq(&clocks);
	//定时器TIM3初始化
	TIM_TimeBaseStructure.TIM_Period = 999; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	
	TIM_TimeBaseStructure.TIM_Prescaler = clocks.PCLK1_Frequency/10000 - 1; //设置用来作为TIMx时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //根据指定的参数初始化TIMx的时间基数单位
	
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE ); //使能指定的TIM2中断,允许更新中断
	
	//中断优先级NVIC设置
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;  //TIM3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //初始化NVIC寄存器

	TIM_Cmd(TIM2, ENABLE);  //使能TIMx	
}

static void bsp_spi2_init(void)
{
    SPI_InitTypeDef spi_init;
    SPI_StructInit(&spi_init);
    spi_init.SPI_Direction = SPI_Direction_1Line_Tx; 
    spi_init.SPI_Mode = SPI_Mode_Master;
    spi_init.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
    spi_init.SPI_FirstBit = SPI_FirstBit_MSB;
    spi_init.SPI_DataSize = SPI_DataSize_8b;
    spi_init.SPI_CPOL = SPI_CPOL_High;
    spi_init.SPI_CPHA = SPI_CPHA_2Edge;
    spi_init.SPI_NSS = SPI_NSS_Soft;
    SPI_Init(SPI2, &spi_init);
    
    SPI_I2S_DMACmd(SPI2, SPI_I2S_DMAReq_Tx, ENABLE); 
    
    SPI_Cmd(SPI2, ENABLE);
    
	NVIC_InitTypeDef nvic_conf;
    nvic_conf.NVIC_IRQChannel = DMA1_Channel5_IRQn;
    nvic_conf.NVIC_IRQChannelPreemptionPriority = 3;
    nvic_conf.NVIC_IRQChannelSubPriority = 0;
    nvic_conf.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&nvic_conf);
}

static void bsp_i2c1_init(void)
{
    I2C_InitTypeDef I2C_InitStructure;
    I2C_DeInit(I2C1);
	I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;								  // I2C模式
	I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;						  //指定时钟占空比，可选 low/high = 2:1 及 16:9 模式
	I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit; // 7位地址
	I2C_InitStructure.I2C_OwnAddress1 = 0xA0;								  //设置I2C设备地址
	I2C_InitStructure.I2C_ClockSpeed = 50000;								  // 100kHz
	I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;								  //使能应答

	I2C_Init(I2C1, &I2C_InitStructure); //初始化I2C1
	I2C_Cmd(I2C1, ENABLE);				//使能I2C1	    
}
static void bsp_i2c2_init(void)
{
    I2C_InitTypeDef I2C_InitStructure;
    I2C_DeInit(I2C2);
	I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;								  // I2C模式
	I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;						  //指定时钟占空比，可选 low/high = 2:1 及 16:9 模式
	I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit; // 7位地址
	I2C_InitStructure.I2C_OwnAddress1 = 0xA0;								  //设置I2C设备地址
	I2C_InitStructure.I2C_ClockSpeed = 100000;								  // 100kHz
	I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;								  //使能应答

	I2C_Init(I2C2, &I2C_InitStructure); //初始化I2C2
	I2C_Cmd(I2C2, ENABLE);				//使能I2C2	
}

void bsp_init(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);	
    
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //时钟使能
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
    //RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
    //RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	//GPIO_PinRemapConfig(GPIO_Remap_I2C1, ENABLE);							   //开启重映射
    
    PWR_BackupAccessCmd( ENABLE );/* 允许修改RTC和后备寄存器*/
    RCC_LSEConfig( RCC_LSE_OFF ); /* 关闭外部低速时钟,PC14+PC15可以用作普通IO*/
    BKP_TamperPinCmd(DISABLE);  /* 关闭入侵检测功能,PC13可以用作普通IO*/
	//GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
    
    bsp_io_init();
    bsp_timer1_init();
    //bsp_timer2_init();
    bsp_timer3_init();
    bsp_timer4_init();
    bsp_spi2_init();
    //bsp_i2c1_init();
    //bsp_i2c2_init();
    
    UART_Configuration(115200); //串口初始化
}

void bsp_delay_block(uint32_t ms)
{
    hal_delay_us_block(ms*1000);
}


