//一种简单的key

#ifndef KEY_H
#define KEY_H

#include "general_in.h"

typedef enum {
    kKeyStateReleased = 0,
    kKeyStatePressed = 1,
}KeyState;

typedef GeneralIn Key;

#define GpioKeyInit GpioGeneralInInit
#define KeyScan GeneralInScan
#define KeyClear(key)   (key)->change = 0

#endif