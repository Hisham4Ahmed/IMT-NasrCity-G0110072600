#ifndef _SRC_MCAL_TIMER1_T1_PRIVATE_H
#define _SRC_MCAL_TIMER1_T1_PRIVATE_H
#include "../../Common/Config.h"
#if Timer1_Driver

typedef enum
{
    // TCCR1A Bits
    WGM10  = 0,
    WGM11  = 1,
    FOC1B  = 2,
    FOC1A  = 3,
    COM1B0 = 4,
    COM1B1 = 5,
    COM1A0 = 6,
    COM1A1 = 7,
    // TCCR1B Bits
    CS10   = 0,
    CS11   = 1,
    CS12   = 2,
    WGM12  = 3,
    WGM13  = 4,
    ICES1  = 6,
    ICNC1  = 7,
    // TIMSK Bits
    TOIE1  = 2,
    OCIE1B = 3,
    OCIE1A = 4,
    TICIE1 = 5,
    // TIFR Bits
    TOV1   = 2,
    OCF1B  = 3,
    OCF1A  = 4,
    ICF1   = 5,
} T1_BitName_t;



typedef enum
{
    T1_Disable,
    T1_NoPrescaller,
    T1_Prescaller_8,
    T1_Prescaller_64,
    T1_Prescaller_256,
    T1_Prescaller_1024,
    T1_ExternalFalling,
    T1_ExternalRising
} T1_ClockSelectOption_t;

typedef enum
{
    T1_Normal_Mode                 = 0,
    T1_PWM_PhaseCorrect_8bit       = 1,
    T1_PWM_PhaseCorrect_9bit       = 2,
    T1_PWM_PhaseCorrect_10bit      = 3,
    T1_CTC_OCR1A_Mode              = 4,
    T1_FastPWM_8bit                = 5,
    T1_FastPWM_9bit                = 6,
    T1_FastPWM_10bit               = 7,
    T1_PWM_PhaseAndFreq_ICR1       = 8,
    T1_PWM_PhaseAndFreq_OCR1A      = 9,
    T1_PWM_PhaseCorrect_ICR1       = 10,
    T1_PWM_PhaseCorrect_OCR1A      = 11,
    T1_CTC_ICR1_Mode               = 12,
    T1_FastPWM_ICR1                = 14,
    T1_FastPWM_OCR1A               = 15
} T1_TimerMode_t;

typedef enum
{
    T1_ICU_Falling = 0x00,
    T1_ICU_Rising  = 0x40,
} T1_ICU_Edge_t;




#define T1_ClockMask  0x07
#endif// _SRC_MCAL_TIMER1_T1_PRIVATE_H
