/*
 * main.c
 *
 *  Created on: Aug 22, 2026
 *      Author: hesham
 */
#include "Application.h"
// Button1  -> B0 -> INput -> Internal Pull Up -> PORTB =1
// Button2  -> B1
// Button3  -> B2

// Led1 -> C0 -> Output
// Buzzer-> D0 -> Output
// Segment -> GroupA -> ouput

void main()
{
	Button_Init();
	HWComponent_Init();
	uint8_t LedControlBtn= NotPressed;
	uint8_t SegCountBtn= NotPressed;
	uint8_t BuzzerTogBtn= NotPressed;
	while(1)
	{
		LedControlBtn=ButtonCheck(1);
		SegCountBtn=ButtonCheck(2);
		BuzzerTogBtn=ButtonCheck(3);
		LedApp(LedControlBtn);
		BuzzerToggleApp(BuzzerTogBtn);
		SegmentCountApp(SegCountBtn);
	}
}










