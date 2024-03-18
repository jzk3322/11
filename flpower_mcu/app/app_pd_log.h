
#ifndef APP_PD_LOG_H
#define APP_PD_LOG_H

#include "stdint.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
// Optional: PD_UFP_log_c, extended from PD_UFP_c to provide logging function.
//           Asynchronous, minimal impact on PD timing.
///////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct 
{
    uint32_t time;
    uint16_t msg_header;
    uint8_t obj_count;
    uint8_t status;
}status_log_t;

typedef enum  
{
    PD_LOG_LEVEL_INFO,
    PD_LOG_LEVEL_VERBOSE
}pd_log_level_t;

#define STATUS_LOG_MASK         15
#define STATUS_LOG_OBJ_MASK     15

typedef struct
{

}App_PD_Log_t;

extern void status_log_event(uint8_t status, uint32_t *obj);
extern int status_log_readline(char *buffer, int maxlen);
#endif
