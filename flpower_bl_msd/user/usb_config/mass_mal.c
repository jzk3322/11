
/* Includes ------------------------------------------------------------------*/
#include "platform_config.h"
#include "mass_mal.h"
#include "air32f10x_flash.h"
#include "FAT16.h"
#include "board.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint32_t Mass_Memory_Size[MAX_LUN+1];
uint32_t Mass_Block_Size[MAX_LUN+1];
uint32_t Mass_Block_Count[MAX_LUN+1];
__IO uint32_t Status = 0;


/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
* Function Name  : MAL_Init
* Description    : Initializes the Media on the STM32
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
uint16_t MAL_Init(uint8_t lun)
{
  uint16_t status = MAL_OK;
  switch (lun)
  {
    case 0:
      FLASH_Unlock();	
      Mass_Memory_Size[0] =   100*1024*1024;  //100M
      Mass_Block_Size[0]  =   board.page_size; //Block 大小为 2048 个字节.
      Mass_Block_Count[0] =   Mass_Memory_Size[0]/Mass_Block_Size[0]; 
      break;
    case 1:
      break;
    default:
      return MAL_FAIL;
  }
  return status;
}
/*******************************************************************************
* Function Name  : MAL_Write
* Description    : Write sectors
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
uint16_t MAL_Write(uint8_t lun, uint64_t Memory_Offset, uint32_t *Writebuff, uint16_t Transfer_Length)
{
  uint8_t STA;
  switch (lun)
  {
    case 0:
        STA=0;
        //W25QXX_Write((u8*)Writebuff, Memory_Offset, Transfer_Length); 
        FATWriteLBA(Memory_Offset,(uint8_t*) Writebuff, (uint32_t) Transfer_Length);
		
      break;
    case 1:
      break;
    default:
      return MAL_FAIL;
  }
  if(STA!=0)return MAL_FAIL;
  return MAL_OK;
}

/*******************************************************************************
* Function Name  : MAL_Read
* Description    : Read sectors
* Input          : None
* Output         : None
* Return         : Buffer pointer
*******************************************************************************/
uint16_t MAL_Read(uint8_t lun, uint64_t Memory_Offset, uint32_t *Readbuff, uint16_t Transfer_Length)
{
  uint8_t STA;
  switch (lun)
  {
    case 0:
			STA=0;
			//W25QXX_Read((u8*)Readbuff, Memory_Offset, Transfer_Length); 
			FATReadLBA(Memory_Offset,(uint8_t*)Readbuff, (uint32_t)Transfer_Length);
        //if(0 == FATReadLBA(Memory_Offset,(uint8_t*)Readbuff, (uint32_t)Transfer_Length))
        //{
        //   STMFLASH_Read(board.ap_address+Memory_Offset,(u16 *)Readbuff, Transfer_Length/2);
        //}		
      break;
    case 1:
      break;
    default:
      return MAL_FAIL;
  }
  if(STA!=0)return MAL_FAIL;
  return MAL_OK;
}

/*******************************************************************************
* Function Name  : MAL_GetStatus
* Description    : Get status
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
uint16_t MAL_GetStatus (uint8_t lun)
{
  switch(lun)
  {
  case 0:
    return MAL_OK;
  case 1:
    return MAL_OK; 
  default:
    return MAL_FAIL;
  } 
}

