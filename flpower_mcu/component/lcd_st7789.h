
#ifndef LCD_ST7789_H
#define LCD_ST7789_H

#include "bsp.h"


#define LCD_SPI_DMA     1
extern void lcd_spi_write_cmd(uint8_t cmd);
extern void lcd_spi_write_data8(uint8_t data);
extern void lcd_spi_write_data16(uint16_t data);


#define lcd_write_cmd               lcd_spi_write_cmd
#define lcd_write_data8             lcd_spi_write_data8
#define lcd_write_data16            lcd_spi_write_data16

#if LCD_SPI_DMA==1
extern void lcd_spi_dma_write(const uint8_t *data, uint16_t len);
extern void lcd_spi_dma_end(void);
extern void lcd_dma_complete(void);
#define lcd_write_dma               lcd_spi_dma_write
#define lcd_write_dma_end           lcd_spi_dma_end
#endif

#define lcd_delay_ms(ms)            bsp_delay_block(ms)

#define lcd_dis_on()                lcd_write_cmd(0x29)
#define lcd_dis_off()               lcd_write_cmd(0x28)

extern void lcd_set_dir(uint8_t dir);
extern void lcd_init(void);
extern void lcd_draw_rect(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, const uint8_t *color_p);
#endif
