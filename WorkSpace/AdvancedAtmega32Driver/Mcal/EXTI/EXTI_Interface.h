#ifndef _MCAL_EXTI_EXTI_INTERFACE_H
#define _MCAL_EXTI_EXTI_INTERFACE_H

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



#endif// _MCAL_EXTI_EXTI_INTERFACE_H
