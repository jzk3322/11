
#include "app_includes.h"

static char rx_data[512];

void task_log(void *para)
{
    size_t received;
    while(1)
    {
        received = sys_log_get(rx_data, 512, 100);
        if(received>0)
        {
            
            board_serial_send(BoardSerialDebugID, rx_data, received);
        }
        else
        {
            received = status_log_readline(rx_data, 512 - 1);
            if (received>0)
                board_serial_send(BoardSerialDebugID, rx_data, received);
        }
    }
}
