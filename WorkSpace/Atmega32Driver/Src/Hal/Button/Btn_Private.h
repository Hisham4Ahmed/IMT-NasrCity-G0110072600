/**
 * @file Btn_Private.h
 * @brief 
 * @author Hisham Ahmed (Hisham.ah.hamed@gmail.com)
 * @date 2026-09-23
 * @version 0.1
 * @copyright Copyright (c) 2026 Gestell. All rights reserved.
 */
#ifndef _HAL_BUTTON_BTN_PRIVATE_H
#define _HAL_BUTTON_BTN_PRIVATE_H

#include "../../Common/Config.h"
#if Button_Driver
typedef enum 
{
    Btn_InternalPullup, 
    Btn_ExternalPullup, 
    Btn_ExternalPullDown,     
}Btn_Connection_t;
typedef enum 
{
    PullUp_Pressed,
    PullUp_NotPressed,
    PullDown_NotPressed=0,
    PullDown_Pressed,    
}Btn_State_t;
#endif// Button_Driver

#endif// _HAL_BUTTON_BTN_PRIVATE_H
