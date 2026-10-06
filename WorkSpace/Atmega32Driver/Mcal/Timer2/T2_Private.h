#ifndef _MCAL_TIMER0_T0_PRIVATE_H
#define _MCAL_TIMER0_T0_PRIVATE_H


typedef enum
{
   //TCCR0
   CS00,
   CS01,
   CS02,
   WGM01,
   COM00,
   COM01,
   WGM00,
   FOC0,
   //TIMSK
   TOIE0=0,
   OCIE0,
   //TIFR,
   TOV0=0,
   OCF0,
}T0_BitName_t;


//TCCR0
//  7 6 5 4 3 2 1 0 
// 
typedef enum
{
    T0_Disable,
    T0_NoPrescaller,
    T0_Prescaller_8,
    T0_Prescaller_64,
    T0_Prescaller_256,
    T0_Prescaller_1024,
    T0_ExternalFalling,
    T0_ExternalRising,
}T0_ClockSelectOption_t;

//  7 6 5 4 3 2 1 0 
//  0 0 0 1 0 0 0 0 
//  0 0 1 0 0 0 0 0 
//  0 0 1 1 0 0 0 0 
typedef enum 
{
    OC0_Disconnect=0x00,
    OC0_Toggle=0x10,
    OC0_Clear=0x20,
    OC0_Set=0x30,
    /*PWM Actions*/
    OC0_NonInverting=0x20,
    OC0_Inverting=0x30,
}T0_OutputCompare_t;
//  wgm00       WGM01
//  7 6 5 4 3 2 1 0 
//  0 1 0 0 0 0 0 0 
//  0 1 0 0 1 0 0 0
typedef enum 
{
    T0_NormalMode = 0x00,
    T0_PWMPhase = 0x40 ,
    T0_CTCMode=0x08,
    T0_PWMFast=0x48,
}T0_TimerMode_t;

typedef enum 
{
    T0_TOVInterruptDisable = 0x00,
    T0_TOVFInterruptEnable = 0x01 ,
    T0_OCMInterruptDisable = 0x00,
    T0_OCMInterruptEnable  = 0x02,
}T0_InterruptState_t;







#endif// _MCAL_TIMER0_T0_PRIVATE_H
