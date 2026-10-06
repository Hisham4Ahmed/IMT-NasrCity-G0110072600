/**
 * @file main.c
 * @brief 
 * @author Hisham Ahmed (Hisham.ah.hamed@gmail.com)
 * @date 2026-09-19
 * @version 0.1
 * @copyright Copyright (c) 2026 Gestell. All rights reserved.
 */
#include <util/delay.h>
#include "Hal/Led/Led_Interface.h"
#include "Mcal/EXTI/EXTI_Interface.h"
#include "Mcal/GIE/GIE_Interface.h"
void ButtonLedAPP(void);
void main ()
{
    //led Init
    Led_Init(DIO_GroupA,DIO_Pin0);
    Led_Init(DIO_GroupA,DIO_Pin4);
    // Button Init
    DIO_DirectionSelectForPin(DIO_GroupD,DIO_Pin2,DIO_Input);
    DIO_InternalPullUpControl(DIO_GroupD,DIO_Pin2,Enable);
    // EXTI Init
    EXTI_Init(Exti0,Exti_Rising);
    EXTI_CallBackFunction(Exti0,ButtonLedAPP);
    EXTI_Enable(Exti0);
    // GIE 
    GIE_Enable();
    while(1)
    {
        Led_Toggle(DIO_GroupA,DIO_Pin0);
        _delay_ms(4000);
    }

}


void ButtonLedAPP(void)
{
    Led_Toggle(DIO_GroupA,DIO_Pin4);
}
