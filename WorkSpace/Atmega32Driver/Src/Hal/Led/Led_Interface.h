#ifndef LED_INTERFACE
#define LED_INTERFACE

#include <stdint.h>
#include "../../Mcal/DIO/DIO_Interface.h"

#include "Led_Private.h"

void Led_Init(uint8_t LedGroup,uint8_t LedPin);

void Led_On(uint8_t LedGroup,uint8_t LedPin,uint8_t ConnectionType);

void Led_Off(uint8_t LedGroup,uint8_t LedPin,uint8_t ConnectionType);

void Led_Toggle(uint8_t LedGroup,uint8_t LedPin);




#endif /* LED_INTERFACE */
