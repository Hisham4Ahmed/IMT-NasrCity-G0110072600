/**
 * @file Btn_Interface.h
 * @brief 
 * @author Hisham Ahmed (Hisham.ah.hamed@gmail.com)
 * @date 2026-09-23
 * @version 0.1
 * @copyright Copyright (c) 2026 Gestell. All rights reserved.
 */
#ifndef _HAL_BUTTON_BTN_INTERFACE_H
#define _HAL_BUTTON_BTN_INTERFACE_H
#include "../../Common/Config.h"

#if Button_Driver
#include "../../Common/BitMath.h"
#include "../../Common/Definition.h"

#include "../../Mcal/DIO/DIO_Interface.h"
#include "Btn_Private.h"
#include "Btn_Config.h"

void BTN_Init(uint8_t BtnGroup,uint8_t BtnPin,uint8_t BtnConnection);
uint8_t BTN_GetState(uint8_t BtnGroup,uint8_t BtnPin,uint8_t BtnConnection);

#endif// Button_Driver


#endif// _HAL_BUTTON_BTN_INTERFACE_H
