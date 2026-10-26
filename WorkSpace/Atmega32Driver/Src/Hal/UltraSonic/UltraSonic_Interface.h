#ifndef _SRC_HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H
#define _SRC_HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H


#include <stdint.h>
#include "../../Mcal/DIO/DIO_Interface.h"
#include "../../Mcal/Timer1/T1_Interface.h"

#include "UltraSonic_Private.h"
#include "UltraSonic_Config.h"


void UltraSonic_Init();
void UltraSonic_Trigger();
uint8_t UltraSonic_GetDistance(uint16_t *DistanceValue);


#endif// _SRC_HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H
