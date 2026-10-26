/**
 * @file KPD_Interface.h
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-09-04
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#ifndef _HAL_KPD_KPD_INTERFACE_H
#define _HAL_KPD_KPD_INTERFACE_H

#include <stdint.h>

#include "Kpd_Private.h"
#include "Kpd_Config.h"

void KPD_Init();
void KPD_GetKPDValue(uint8_t *KPD_Value);

#endif// _HAL_KPD_KPD_INTERFACE_H
