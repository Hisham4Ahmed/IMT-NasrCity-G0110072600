#include "T1_Interface.h"



/*Generic Public API*/
void T1_TimerReset()
{
    TCNT1_Reg = 0 ; 
}
uint16_t T1_GetTimerValue()
{
    return (TCNT1_Reg);
}
void T1_SetTimerValue(uint16_t TimerValue)
{
    TCNT1_Reg = TimerValue;
}
void T1_SetClock(uint8_t PrescallerValue)
{
    TCCR1B_Reg = (TCCR1B_Reg & ~ T1_ClockMask ) | (PrescallerValue & T1_ClockMask );
}

static void (*GlobalICUPF)(void)=NULL;
/*ICU*/
void T1ICU_Init()
{
    //  1- Normal Mode  
        ClearBit (TCCR1A_Reg,WGM10);
        ClearBit (TCCR1A_Reg,WGM11);
        ClearBit (TCCR1B_Reg,WGM12);
        ClearBit (TCCR1B_Reg,WGM13);
    //  2- Inital Edge && Enable Interrupt 
    T1ICU_SetEdge(ICU_EdgeSelectInit);
    //  3- Enable Interrupt 
    //  T1ICU_EnableInterrupt();
    // 4- Clock Select 
    T1_SetClock(T1_ClockSelectInit);
}
void T1ICU_EnableInterrupt()
{
    SetBit(TIMSk_Reg,TICIE1);
}
void T1ICU_DisableInterrupt()
{
    ClearBit(TIMSk_Reg,TICIE1);
}
void T1ICU_SetEdge(uint8_t EdgeSelect)
{
    T1ICU_DisableInterrupt();
    if(EdgeSelect == T1_ICU_Rising)
    {
        SetBit(TCCR1B_Reg,ICES1);
    }
    else
    {
        ClearBit(TCCR1B_Reg,ICES1);
    }
    SetBit(TIFR_Reg,ICF1);
    T1ICU_EnableInterrupt();
}
void T1ICU_SetCallBack(void (*PF) (void))
{
    if(PF!=NULL)
    {
        GlobalICUPF=PF;
    }
}
void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
    if(GlobalICUPF!=NULL)
    {
        GlobalICUPF();
    }
}
uint16_t T1ICU_GetCaptureValue()
{
    return (ICR1_Reg);
}