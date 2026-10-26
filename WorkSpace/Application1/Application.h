/*
 * Application.h
 *
 *  Created on: Aug 22, 2026
 *      Author: hesham
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "Atmega32Register.h"
#include "BitMath.h"
#include <stdint.h>
#define Pressed 0
#define NotPressed 1
void LedApp(uint8_t State);
void SegmentCountApp(uint8_t State);
void BuzzerToggleApp(uint8_t State);
uint8_t ButtonCheck(uint8_t ButtonNo);
void Button_Init();
void HWComponent_Init();
#endif /* APPLICATION_H_ */
