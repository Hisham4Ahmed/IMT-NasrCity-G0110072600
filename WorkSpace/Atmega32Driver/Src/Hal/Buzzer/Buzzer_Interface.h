/**
 * @file Buzzer_Interface.h
 * @brief 
 * @author Hisham Ahmed (Hisham.ah.hamed@gmail.com)
 * @date 2026-09-23
 * @version 0.1
 * @copyright Copyright (c) 2026 Gestell. All rights reserved.
 */
#ifndef BUZZER_INTERFACE_H
#define BUZZER_INTERFACE_H
#include "../../Common/Config.h"
#if Buzzer_Driver

#include <stdint.h>
#include "../../Common/BitMath.h"
#include "../../Common/Definition.h"
#include "../../Mcal/DIO/DIO_Interface.h"
#include "Buzzer_Private.h"
#include "Buzzer_Config.h"

void Buzzer_Init(void);
void Buzzer_On(void);
void Buzzer_Off(void);
void Buzzer_Toggle(void);

#endif// Buzzer_Driver

#endif// _HAL_BUZZER_BUZZER_INTERFACE_H
