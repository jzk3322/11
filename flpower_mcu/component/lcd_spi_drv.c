
#include "bsp.h"

#define LCD_CS_L() GPIO_ResetBits(BSP_LCD_CS_PORT, BSP_LCD_CS_GPIO) 
#define LCD_CS_H() GPIO_SetBits(BSP_LCD_CS_PORT, BSP_LCD_CS_GPIO)


#define LCD_SCLK_L() GPIO_ResetBits(GPIOB,GPIO_Pin_13)//SCL=SCLK
#define LCD_SCLK_H() GPIO_SetBits(GPIOB,GPIO_Pin_13)

#define LCD_MOSI_L() GPIO_ResetBits(GPIOB,GPIO_Pin_15)//SDA=MOSI
#define LCD_MOSI_H() GPIO_SetBits(GPIOB,GPIO_Pin_15)

void lcd_spi_write_byte(uint8_t byte)
{
    LCD_CS_L(); //CS=0
    
    while(SPI_I2S_GetFlagStatus(BSP_LCD_SPI, SPI_I2S_FLAG_BSY) == SET); //等待传输完成
    SPI_DataSizeConfig(BSP_LCD_SPI, SPI_DataSize_8b);
    SPI_I2S_SendData(BSP_LCD_SPI, byte);
    while(SPI_I2S_GetFlagStatus(BSP_LCD_SPI, SPI_I2S_FLAG_BSY) == SET); //等待传输完成
/*	    u8 i;	
    for(i=0;i<8;i++)
	{			  
		LCD_SCLK_L();
		if(byte&0x80)
		{
		   LCD_MOSI_H();
		}
		else
		{
		   LCD_MOSI_L();
		}
		LCD_SCLK_H();
		byte<<=1;
	}
*/
    LCD_CS_H();
}

void lcd_spi_write_cmd(uint8_t cmd)
{
    GPIO_ResetBits(BSP_LCD_DC_PORT, BSP_LCD_DC_GPIO); //D/C=0, 指令
    lcd_spi_write_byte(cmd);
    GPIO_SetBits(BSP_LCD_DC_PORT, BSP_LCD_DC_GPIO); //D/C=1, 数据
}

void lcd_spi_write_data8(uint8_t data)
{
    lcd_spi_write_byte(data);
}

void lcd_spi_write_data16(uint16_t data)
{
    lcd_spi_write_byte(data>>8);
    lcd_spi_write_byte(data);
}

void lcd_spi_dma_write(const uint8_t *data, uint16_t len)
{
    SPI_DataSizeConfig(BSP_LCD_SPI, SPI_DataSize_16b);
    
    DMA_InitTypeDef dma_conf;
    
    dma_conf.DMA_BufferSize = len;
    dma_conf.DMA_M2M = DMA_M2M_Disable;
    dma_conf.DMA_DIR = DMA_DIR_PeripheralDST;
    dma_conf.DMA_MemoryBaseAddr = (uint32_t)data;
    dma_conf.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
    dma_conf.DMA_MemoryInc = DMA_MemoryInc_Enable;
    dma_conf.DMA_PeripheralBaseAddr = (uint32_t)&(BSP_LCD_SPI->DR);
    dma_conf.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
    dma_conf.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    dma_conf.DMA_Priority = DMA_Priority_Medium;
    dma_conf.DMA_Mode = DMA_Mode_Normal;
    
    DMA_Init(BSP_LCD_DMA_CH, &dma_conf);
    
    DMA_ITConfig(BSP_LCD_DMA_CH, DMA_IT_TC, ENABLE); //开启DMA传输完成中断
    LCD_CS_L();
    DMA_Cmd(BSP_LCD_DMA_CH, ENABLE); //启动传输
}

void lcd_spi_dma_end(void)
{
    while(SPI_I2S_GetFlagStatus(BSP_LCD_SPI, SPI_I2S_FLAG_BSY) == SET);
    LCD_CS_H();
}