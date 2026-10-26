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
#ifndef KPD_INTERFACE
#define KPD_INTERFACE

#include <stdint.h>

#include "KPD_Private.h"
#include "KPD_Config.h"

void KPD_Init();
void KPD_GetKPDValue(uint8_t *KPD_Value);

#endif /* KPD_INTERFACE */
