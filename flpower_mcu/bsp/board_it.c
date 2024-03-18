
#include "board.h"
void DMA1_Channel5_IRQHandler(void)
{
    if(DMA_GetITStatus(DMA1_FLAG_TC5) != RESET) {
        /* 清除DMA中断标志位 */
        DMA_ClearITPendingBit(DMA1_FLAG_TC5);
        /* 复位DMA */
        DMA_Cmd(DMA1_Channel5, DISABLE);
        
        /* 发送TaskNotify并进行一次任务调度 */
        lcd_dma_complete(); 
    }
}

