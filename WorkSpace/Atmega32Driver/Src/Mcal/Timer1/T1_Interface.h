#ifndef _SRC_MCAL_TIMER1_T1_INTERFACE_H
#define _SRC_MCAL_TIMER1_T1_INTERFACE_H


#include <stdint.h>
#include "../../Common/BitMath.h"
#include "../../Common/Definition.h"
#include "../Atmega32Registers.h"
#include "T1_Private.h"
#include "T1_Config.h"

/*Generic Public API*/
void T1_TimerReset();
uint16_t T1_GetTimerValue();
void T1_SetTimerValue(uint16_t TimerValue);
void T1_SetClock(uint8_t PrescallerValue);
/*ICU*/
void T1ICU_Init();
void T1ICU_EnableInterrupt();
void T1ICU_DisableInterrupt();
void T1ICU_SetCallBack(void (*PF) (void));
void T1ICU_SetEdge(uint8_t EdgeSelect);
uint16_t T1ICU_GetCaptureValue();



#endif// _SRC_MCAL_TIMER1_T1_INTERFACE_H
