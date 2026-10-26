/**
 * @file LCD_Interface.h
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-09-03
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#ifndef _HAL_LCD_LCD_INTERFACE_H
#define _HAL_LCD_LCD_INTERFACE_H

#include <stdint.h>
#include <util/delay.h>
#include "../../Mcal/DIO/DIO_Interface.h"
#include "Lcd_Private.h"
#include "Lcd_Config.h"



void LCD_Init();
void LCD_SendCommand(uint8_t Command);
void LCD_WriteCharacter(uint8_t Character);
void LCD_WriteString(uint8_t *String);
void LCD_WriteNumber(int32_t Number);
void LCD_MoveTo(uint8_t Line, uint8_t Digit);
void LCD_StoreSpecialCharacter(uint8_t * SpecialCharacter , uint8_t Location);








#endif// _HAL_LCD_LCD_INTERFACE_H
