/*
 * Application.c
 *
 *  Created on: Aug 22, 2026
 *      Author: hesham
 */
#include "Application.h"
#include <util/delay.h>
#include <stdint.h>
// Anode LedON ->0 Ledoff -> 1
//  h g f e d c b a
//  7 6 5 4 3 2 1 0
//  1 1 0 0 0 0 0 0
//  1 1 1 1 1 1 0 0
//  1 0 1 0 0 1 0 0
//  1 0 1 1 0 0 0 0
//  1 0 0 1 1 0 0 1
//  h g f e d c b a
//  1 0 0 1 0 0 1 0
//  1 0 0 0 0 0 1 0
//  1 0 1 1 1 0 0 0
//  1 0 0 0 0 0 0 0
//  1 0 0 1 0 0 0 0
#define AnodeZero   0xC0
#define AnodeOne    0xFC
#define AnodeTwo    0xA4
#define AnodeThree  0xB0
#define AnodeFour   0x99
#define AnodeFive   0x92
#define AnodeSix    0x82
#define AnodeSeven  0xB8
#define AnodeEight  0x80
#define AnodeNine   0x90
size_t add(size_t x)
{
return x++;
}
static uint8_t Number[10]=
{
		AnodeZero ,
		AnodeOne  ,
		AnodeTwo  ,
		AnodeThree,
		AnodeFour ,
		AnodeFive ,
		AnodeSix  ,
		AnodeSeven,
		AnodeEight,
		AnodeNine ,
};
void LedApp(uint8_t State)
{
	if(State==Pressed)
	{
		ClearBit(PORTC_Reg,0);
	}
	else if (State==NotPressed)
	{
		SetBit(PORTC_Reg,0);
	}
}

void SegmentCountApp(uint8_t State)
{
	static uint8_t Count = 0 ;
	PORTA_Reg=Number[Count];
	if(State==Pressed)
	{
		Count++;
		if(Count>9)
		{
			Count=0;
		}
		PORTA_Reg=Number[Count];
	}
	else
	{

	}
}
void BuzzerToggleApp(uint8_t State)
{
	if(State==Pressed)
	{
		ToggleBit(PORTD_Reg,0);
		_delay_ms(500);
	}
	else if (State==NotPressed)
	{
		ClearBit(PORTD_Reg,0);
	}

}

uint8_t ButtonCheck(uint8_t ButtonNo)
{
	if(ButtonNo==1)
	{
		return ReadBit(PINB_Reg,0);
	}
	else if (ButtonNo==2)
	{
		if(ReadBit(PINB_Reg,1)==Pressed)
		{
			_delay_ms(50);
			return ReadBit(PINB_Reg,1);
		}
	}
	else if(ButtonNo==3)
	{

			return ReadBit(PINB_Reg,2);
	}
	else
	{
		return 0xFF ;
	}
	return 0xFF;
}
void Button_Init()
{
	// init
	ClearBit(DDRB_Reg,0);// Select INput
	ClearBit(DDRB_Reg,1);
	ClearBit(DDRB_Reg,2);
	SetBit(PORTB_Reg,0);// Enable Internal Pull Up
	SetBit(PORTB_Reg,1);
	SetBit(PORTB_Reg,2);
}
void HWComponent_Init()
{
	SetBit(DDRC_Reg,0); // Led
	SetBit(DDRD_Reg,0); // buzzer
	DDRA_Reg=0xFF;
}






