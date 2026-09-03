/*
 * main.c
 *
 *  Created on: Aug 22, 2026
 *      Author: hesham
 */
#include <util/delay.h>
#include "Mcal/DIO/DIO_Interface.h"
#include "Hal/Led/Led_Interface.h"
#include "Hal/LCD/LCD_Interface.h"
void main()
{
LCD_Init();
// LCD_WriteCharacter('H');
LCD_WriteString("Omar");
LCD_MoveTo(Lcd_Line2,5);
LCD_WriteString("IMT");
while(1);
	
}



