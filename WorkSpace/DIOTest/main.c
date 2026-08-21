///*
// * main.c
// *
// *  Created on: Aug 21, 2026
// *      Author: hesham
// */
//
//#include "Atmega32Register.h"
//#include "BitMath.h"
//#include <util/delay.h>
//// DDR -> Direction  (select input or Output )
//// PORT -> OutputValue(Select Low or High)
//// PIN -> InputValue(Read Input Value )
//
//void main()
//{
//	// Update GroupA as Output
//	DDRA_Reg=0b11111111; // Bin
//	DDRB_Reg=255;
//	DDRC_Reg=0xFF;
//	// Update the Pin 5 in GroupD as Output
//		SetBit(DDRD_Reg,5);
//	// Update the Pin 3 in GroupC as Input
//		ClearBit(DDRC_Reg,3);
//	// toggle for Led for each 1 Sec
//	// GroupB Pin 2 as Output
//		SetBit(DDRB_Reg,2);//Buzzer
//		SetBit(DDRA_Reg,3);// Led
//// Super Loop System
//
//	while(1)
//	{
////		// Toggle Function
////		ToggleBit(PORT1_Reg,3);
//
////		// waiting
////			// type (1 Blocking 2- Timer 3- Os)
////		_delay_ms(1000);
//
//	}
//}





#include "Atmega32Register.h"
#include "BitMath.h"
#include <util/delay.h>
#define Pressed     0
#define NotPressed  1

void main()
{
	// butto1 groupA  pin 0
	// Internal Pull Up
	ClearBit(DDRA_Reg,0);
	SetBit(PORTA_Reg,0);// Enable for Internal Pull Up
	// button2 groupc pin 6
	ClearBit(DDRC_Reg,6);
	uint8_t Button1State = NotPressed ;
	uint8_t Button2State = NotPressed ;
	// Led GroupC pin 3
	SetBit(DDRC_Reg,3);
	while(1)
	{
		Button2State=ReadBit(PINC_Reg,6);
		if(Button2State==Pressed)
		{
			// Led On
			SetBit(PORTC_Reg,3);
		}
		else if(Button2State==NotPressed)
		{
			ClearBit(PORTC_Reg,3);
		}
	}








}

//void main()
//{
//	// GroupA -> SevenSegment1 -> Cathod
//	// GroupB -> SevenSegment2 -> Anode
//	DDRA_Reg=0xFF;
//	DDRB_Reg=0xFF;
//	while(1)
//	{
////		PORTA_Reg=0x4F;
//		PORTA_Reg=0xB0;
//	}
//}
//












