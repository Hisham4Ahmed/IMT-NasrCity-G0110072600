#ifndef LCD_INTERFACE
#define LCD_INTERFACE
#include <stdint.h>
#include "../../Mcal/DIO/DIO_Interface.h"

#include "LCD_Private.h"
#include "LCD_Config.h"

void LCD_Init();
void LCD_SendCommand(uint8_t Command);
void LCD_WriteCharacter(uint8_t Character);
void LCD_WriteString(uint8_t *String);
void LCD_WriteNumber(int32_t Number);
void LCD_MoveTo(uint8_t Line, uint8_t Digit);
void LCD_StoreSpecialCharacter(uint8_t * SpecialCharacter , uint8_t Location);








#endif /* LCD_INTERFACE */
