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
#include "Hal/KPD/KPD_Interface.h"
void main()
{
    KPD_Init();
    LCD_Init();
    LCD_WriteString("Welcome");
    _delay_ms(1000);
    uint8_t BtnValue = 0;
    while(1)
    {
        KPD_GetKPDValue(&BtnValue);

        if(BtnValue!=0xFF)
        {
            LCD_WriteCharacter(BtnValue);

        }
        // else
        // {
        //     LCD_MoveTo(Lcd_Line1,1);
        //     LCD_WriteString("              ");
        // }

    }
	
}



