/**
 * @file Buzzer_Config.h
 * @brief 
 * @author Hisham Ahmed (Hisham.ah.hamed@gmail.com)
 * @date 2026-09-23
 * @version 0.1
 * @copyright Copyright (c) 2026 Gestell. All rights reserved.
 */
#ifndef _HAL_BUZZER_BUZZER_CONFIG_H
#define _HAL_BUZZER_BUZZER_CONFIG_H

#include "../../Common/Config.h"

#if Buzzer_Driver

#include "../../Mcal/DIO/DIO_Interface.h"

#define Buzzer_ConnectionType Buzzer_NPNConnection
#define BuzzerGroup           DIO_GroupA      
#define BuzzerPin             DIO_Pin0    

#endif// Buzzer_Driver


#endif// _HAL_BUZZER_BUZZER_CONFIG_H
