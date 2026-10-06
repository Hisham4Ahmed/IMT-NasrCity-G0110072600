/**
 * @file LCD_Program.c
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-09-03
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include "LCD_Interface.h"
#include <util/delay.h>

void LCD_Init()
{
    #if LCD_Mode== Lcd_8BitMode
        DIO_DirectionSelectForPin(RSGroup,RSPin,DIO_Output);
        DIO_DirectionSelectForPin(RWGroup,RWPin,DIO_Output);
        DIO_DirectionSelectForPin(EGroup,EPin,DIO_Output);
        DIO_DirectionSelectForGroup(DataGroup,DIO_AllHigh);
        /*Init*/
        // 1- wait for 30 msec 
            _delay_ms(35);
        // 2- sent the function set 
            LCD_SendCommand(Lcd_FunctionSet);
        // 3- wait for 1msec
            _delay_ms(1);
        // 4- Sent the Display on Off 
            LCD_SendCommand(Lcd_DisplayOnOff);
        // 5- wait for 1msec
             _delay_ms(1);
        // 6- Sent Clear  
            LCD_SendCommand(Lcd_ClearScreen);
        // 7- wait for 2msec
             _delay_ms(2);
        // 8- Entry Mode sent 
            LCD_SendCommand(Lcd_EntryMode);
    #elif LCD_Mode==Lcd_4BitMode
    #else 
            #error "Invalid Lcd Mode"
    #endif
}
void LCD_SendCommand(uint8_t Command)
{
    #if LCD_Mode==Lcd_8BitMode
        //RS -> 0 
        DIO_WriteForPin(RSGroup,RSPin,DIO_Low);
        //RW -> 0 
        DIO_WriteForPin(RWGroup,RWPin,DIO_Low);
        //Data =  Command 
        DIO_WriteForGroup(DataGroup,Command);
        //E-> 1 
        DIO_WriteForPin(EGroup,EPin,DIO_High);
        // Wait 1msec
        _delay_ms(1);
        // E-> 0 
        DIO_WriteForPin(EGroup,EPin,DIO_Low);
    #elif LCD_Mode==Lcd_4BitMode
    #else 
            #error "Invalid Lcd Mode"
    #endif
        
}
void LCD_WriteCharacter(uint8_t Character)
{
    #if LCD_Mode==Lcd_8BitMode
        //RS -> 1 
        DIO_WriteForPin(RSGroup,RSPin,DIO_High);
        //RW -> 0 
        DIO_WriteForPin(RWGroup,RWPin,DIO_Low);
        //Data =  Character
        DIO_WriteForGroup(DataGroup,Character);
        //E-> 1 
        DIO_WriteForPin(EGroup,EPin,DIO_High);
        // Wait 1msec
        _delay_ms(1);
        // E-> 0 
        DIO_WriteForPin(EGroup,EPin,DIO_Low);
    #elif LCD_Mode==Lcd_4BitMode
    #else 
        #error "Invalid Lcd Mode"
    #endif

}
void LCD_WriteString(uint8_t *String)
{
    if(String!=NULL)
    {
        uint8_t Index = 0 ;
        while(String[Index]!=NullChar)
        {
            LCD_WriteCharacter(String[Index]);
            Index++;
        }
    }
}

void LCD_MoveTo(uint8_t Line, uint8_t Digit)
{
    uint8_t DDRAM_Address = 0 ;
    switch(Line)
    {
        case Lcd_Line1: DDRAM_Address = Lcd_Line1Address+Digit;break;
        case Lcd_Line2: DDRAM_Address = Lcd_Line2Address+Digit;break;
        default:break;
    }
    LCD_SendCommand(Lcd_SetDDRAMCommand|DDRAM_Address);
}
void LCD_StoreSpecialCharacter(uint8_t * SpecialCharacter , uint8_t Location)
{
    if(SpecialCharacter==NULL||Location>Lcd_CGRAMMaxLocation)
    {
        return ; 
    }

    uint8_t LocationAddress = Location*Lcd_CGRAMMaxSizeofLocation;
    LCD_SendCommand(Lcd_SetCGRAMCommand|LocationAddress);
    uint8_t counter = 0 ;
    for(counter=0;counter<Lcd_CGRAMMaxSizeofLocation;counter++)
    {
        LCD_WriteCharacter(SpecialCharacter[counter]);
    }
    LCD_MoveTo(Lcd_Line1,0);

}
void LCD_WriteNumber(int32_t Number)
{
    uint8_t NumberDigits[10]={0};
    uint8_t Index = 0 ;
    int8_t Counter = 0 ;
    if(Number==0)
    {
        LCD_WriteCharacter('0');
        return ;
    }
    if(Number<0)
    {
       LCD_WriteCharacter('-');
       Number = Number * -1 ; 
    }
    while(Number!=0)
    {
        // spreted Numbers 
        NumberDigits[Index] = (Number %10)+'0';
        Number=Number/10;
        Index++;
    }
    for(Counter=Index-1;Counter>=0;Counter--)
    {
        LCD_WriteCharacter(NumberDigits[Counter]);
    }
}