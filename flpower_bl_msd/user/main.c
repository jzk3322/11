#include "board.h"
#include "FAT16.h"
	
int main(void)
{	
    board_init();

    if(board_key_press())
    {
        board_usb_config();
        fat_event_set(FAT_EVENT_IDLE);
        while (bDeviceState != CONFIGURED); //等待PC连接
        while(1)
        {
            if(fat_event.change)
            {
                if(fat_event.info!=FAT_EVENT_IDLE)
                {
                    switch(fat_event.info)
                    {
                    case FAT_EVENT_SUCCESS:
                        FATSetStatusFileName("SUCCESS");
                        
                        //board_jump_to_app();
                        break;
                    case FAT_EVENT_UNKOWN:
                        FATSetStatusFileName("UNKNOW");
                        break;
                    case FAT_EVENT_LARGE:
                        FATSetStatusFileName("LARGE");
                        break;
                    case FAT_EVENT_ERRAPP:
                        FATSetStatusFileName("ERRAPP");
                        break;
                    default:
                        
                        break;
                    }
                    board_usb_config(); //重新枚举
                }
                fat_event.change = 0;
                //fat_event.info = 0;
            }
            Delay_Ms(100);
        }
    }
    else //直接跳转到app
        board_jump_to_app();
}
