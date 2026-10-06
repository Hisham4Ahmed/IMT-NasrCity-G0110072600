/**
 * @file Buzzer_Private.h
 * @brief 
 * @author Hisham Ahmed (Hisham.ah.hamed@gmail.com)
 * @date 2026-09-23
 * @version 0.1
 * @copyright Copyright (c) 2026 Gestell. All rights reserved.
 */
#ifndef _HAL_BUZZER_BUZZER_PRIVATE_H
#define _HAL_BUZZER_BUZZER_PRIVATE_H
#include "../../Common/Config.h"
#if Buzzer_Driver
    typedef enum
    {
        Buzzer_StateOff = 0,
        Buzzer_StateOn  = 1
    }Buzzer_State_t;
    typedef enum
    {
        Buzzer_PNPConnection =  0,
        Buzzer_NPNConnection =  1, 
    }Buzzer_Connection_t;
#endif// Buzzer_Driver

#endif// _HAL_BUZZER_BUZZER_PRIVATE_H
