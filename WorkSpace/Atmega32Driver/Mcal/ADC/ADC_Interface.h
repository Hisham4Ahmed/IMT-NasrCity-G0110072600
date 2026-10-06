#ifndef _MCAL_ADC_ADC_INTERFACE_H
#define _MCAL_ADC_ADC_INTERFACE_H
#include <stdint.h>
#include "../../Common/BitMath.h"
#include "../../Common/Definition.h"
#include "../Atmega32Registers.h"
#include "ADC_Private.h"
#include "ADC_Config.h"
/*Initialiation*/
void ADC_Init();
void ADC_DeInit();
/*Control*/
void ADC_Enable();
void ADC_Disable();
void ADC_EnableInterrupt();
void ADC_DisableInterrupt();
/*Polling*/
uint8_t ADC_Read(uint8_t Channel,uint16_t *DigitalValue,uint32_t MaxTimeOut);
/*Interrupt*/
uint8_t ADC_StartConversion(uint8_t Channel);
uint8_t ADC_SetCallBack(void(*ADC_PF)(uint16_t Result));


 
static void ADC_SelectChannel(uint8_t Channel);
uint8_t ADC_GetStatus();
#endif// _MCAL_ADC_ADC_INTERFACE_H
