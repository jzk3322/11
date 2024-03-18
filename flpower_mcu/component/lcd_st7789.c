
#include "lcd_st7789.h"

static uint32_t x_offset, y_offset;

#define lcd_rst_L()   GPIO_ResetBits(BSP_LCD_RST_PORT, BSP_LCD_RST_GPIO);
#define lcd_rst_H()   GPIO_SetBits(BSP_LCD_RST_PORT, BSP_LCD_RST_GPIO);

#if LCD_SPI_DMA==1
SemaphoreHandle_t lcd_dma_complete_flag;
void lcd_dma_complete(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE; 
    xSemaphoreGiveFromISR(lcd_dma_complete_flag, &xHigherPriorityTaskWoken);
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);     
}
#endif

void lcd_reg_init(void)
{
    lcd_write_cmd(0x11); //Sleep out 
	lcd_delay_ms(120);              //Delay 120ms 

    lcd_write_cmd(0x36);
	lcd_write_data8(0xc0);

	lcd_write_cmd(0x3A);			
	lcd_write_data8(0x05);

	lcd_write_cmd(0xB2);			
	lcd_write_data8(0x0C);
	lcd_write_data8(0x0C); 
	lcd_write_data8(0x00); 
	lcd_write_data8(0x33); 
	lcd_write_data8(0x33); 			

	lcd_write_cmd(0xB7);			
	lcd_write_data8(0x35);

	lcd_write_cmd(0xBB);			
	lcd_write_data8(0x32); //Vcom=1.35V
					
	lcd_write_cmd(0xC2);
	lcd_write_data8(0x01);

	lcd_write_cmd(0xC3);			
	lcd_write_data8(0x15); //GVDD=4.8V  颜色深度
				
	lcd_write_cmd(0xC4);			
	lcd_write_data8(0x20); //VDV, 0x20:0v

	lcd_write_cmd(0xC6);			
	lcd_write_data8(0x0F); //0x0F:60Hz        	

	lcd_write_cmd(0xD0);			
	lcd_write_data8(0xA4);
	lcd_write_data8(0xA1); 

	lcd_write_cmd(0xE0);
	lcd_write_data8(0xD0);   
	lcd_write_data8(0x08);   
	lcd_write_data8(0x0E);   
	lcd_write_data8(0x09);   
	lcd_write_data8(0x09);   
	lcd_write_data8(0x05);   
	lcd_write_data8(0x31);   
	lcd_write_data8(0x33);   
	lcd_write_data8(0x48);   
	lcd_write_data8(0x17);   
	lcd_write_data8(0x14);   
	lcd_write_data8(0x15);   
	lcd_write_data8(0x31);   
	lcd_write_data8(0x34);   

	lcd_write_cmd(0xE1);     
	lcd_write_data8(0xD0);   
	lcd_write_data8(0x08);   
	lcd_write_data8(0x0E);   
	lcd_write_data8(0x09);   
	lcd_write_data8(0x09);   
	lcd_write_data8(0x15);   
	lcd_write_data8(0x31);   
	lcd_write_data8(0x33);   
	lcd_write_data8(0x48);   
	lcd_write_data8(0x17);   
	lcd_write_data8(0x14);   
	lcd_write_data8(0x15);   
	lcd_write_data8(0x31);   
	lcd_write_data8(0x34);
	lcd_write_cmd(0x21); 

	lcd_write_cmd(0x28);
    lcd_set_dir(0);
}

void lcd_init(void)
{
    
    lcd_dma_complete_flag = xSemaphoreCreateBinary();
    lcd_rst_L();
    lcd_delay_ms(100);
    lcd_rst_H();
    lcd_delay_ms(200);
    
    lcd_write_cmd(0x01); //软复位
    lcd_delay_ms(10);
    lcd_reg_init();
}

void lcd_draw_rect(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, const uint8_t *color_p)
{
    lcd_write_cmd(0x2A); //设置列地址
    lcd_write_data16(x0+x_offset);
    lcd_write_data16(x1+x_offset);
    lcd_write_cmd(0x2B); //设置行地址
    lcd_write_data16(y0+y_offset);
    lcd_write_data16(y1+y_offset);
    lcd_write_cmd(0x2C);
#if LCD_SPI_DMA==1
    lcd_write_dma(color_p, (x1-x0+1)*(y1-y0+1));
    xSemaphoreTake(lcd_dma_complete_flag, portMAX_DELAY);
    lcd_write_dma_end();
#else
    uint16_t i, j;
    for(i=y0;i<=y1;i++)
	{													   	 	
		for(j=x0;j<=x1;j++)
		{
			lcd_write_data8(*color_p++);
			lcd_write_data8(*color_p++);
            //lcd_write_data16(0xff00);
		}
	}
#endif
}

void lcd_set_dir(uint8_t dir)
{
    lcd_write_cmd(0x36);
    switch(dir)
    {
        case 1:
            lcd_write_data8(0x00);
            break;
        case 2:
            lcd_write_data8(0x00);
            break;
        case 3:
            lcd_write_data8(0x00);
            break;
        case 0:
        default:
            x_offset = 0;
            y_offset = 80;
            lcd_write_data8(0xc0);
            break;
    }
}