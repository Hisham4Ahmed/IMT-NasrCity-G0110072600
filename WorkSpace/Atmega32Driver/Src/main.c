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
#include "Hal/Buzzer/Buzzer_Interface.h"
#include "Mcal/Timer0/T0_Interface.h"
#include "Mcal/GIE/GIE_Interface.h"
/**
 * T1 -> 300msec  -> Buzzer Toggle At 300msec 
 * T2 -> 2000msec -> Led Toggle At 2000msec 
 * Req-> 100msec -> 3  
 * Timer0 8bit - FCPU =8mhz  - Prescaller 64
 * CLK = 64/8000 000 => 8usec
 * OVF = 256*Clktime = 256*8usec = 2048usec
 * No Of OVF Count = 100 000 / 2048 =48.828125 
 * preload = 256*(1-0.828125) = 44 
 */
static volatile uint32_t SystemTick = 0 ; 
void App_TickUpdate()
{
    SystemTick++;
}
 void main ()
{
    //Buzzer 300msec
    Led_Init(DIO_GroupA,DIO_Pin0);
    //Led 2000msec 
    Led_Init(DIO_GroupA,DIO_Pin1);
    T0_NormalCallBack(App_TickUpdate);
    T0_NormalInit();
    GIE_Enable();
    uint32_t LastTimeofBuzzer = 0; 
    uint32_t LastTimeofLed = 0; 

    while(1)
    {
        if((SystemTick - LastTimeofBuzzer) >=3 )
        {
            Led_Toggle(DIO_GroupA,DIO_Pin0);
            LastTimeofBuzzer = SystemTick;
        }
        if((SystemTick - LastTimeofLed) >= 20 )
        {
            Led_Toggle(DIO_GroupA,DIO_Pin1);
            LastTimeofLed = SystemTick;
        }
    }




    /*
    Led_Init(DIO_GroupB,DIO_Pin3);
    T0_PwmInit();
    uint8_t LightIntensity=0;
    while (1)
    {
        for(LightIntensity=0;LightIntensity<=100;LightIntensity++)
        {
            T0_SetDutyCycle(LightIntensity);
            _delay_ms(50);
        }
        for(LightIntensity=100;LightIntensity>0;LightIntensity--)
        {
            T0_SetDutyCycle(LightIntensity);
            _delay_ms(50);
        }
    }
    */

}


void ButtonLedAPP(void)
{
    Led_Toggle(DIO_GroupA,DIO_Pin4);
}
