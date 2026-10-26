/**
 * @file EXTI_Interface.h
 * @brief 
 * @author Hisham Ahmed (Hisham.ah.hamed@gmail.com)
 * @date 2026-10-06
 * @version 0.1
 * @copyright Copyright (c) 2026 Gestell. All rights reserved.
 */
#ifndef _MCAL_EXTI_EXTI_INTERFACE_H
#define _MCAL_EXTI_EXTI_INTERFACE_H
#include "../../Common/Config.h"
#if EXTI_Driver
#include "../Atmega32Registers.h"
#include "../../Common/BitMath.h"
#include "../../Common/Definition.h"


#include "EXTI_Private.h"
#include "EXTI_Config.h"

void EXTI_Init(uint8_t InterruptNumber , uint8_t SensControl);

void EXTI_Enable(uint8_t InterruptNumber);

void EXTI_Disable(uint8_t InterruptNumber);

/*CallBacks*/

void EXTI_CallBackFunction(uint8_t InterruptNumber , void (*PF)(void));
#endif// EXTI_Driver


#endif// _MCAL_EXTI_EXTI_INTERFACE_H
