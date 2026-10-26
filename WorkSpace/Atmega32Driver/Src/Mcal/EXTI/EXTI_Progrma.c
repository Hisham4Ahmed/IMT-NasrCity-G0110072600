
#include "EXTI_Interface.h"
// Rule 
// Reg = Reg & ~ Mask  | NewValue 
void EXTI_Init(uint8_t InterruptNumber , uint8_t SensControl)
{
    if(InterruptNumber == Exti0)
    {
        MCUCR_Reg = MCUCR_Reg&~0x03 | (SensControl<<ISC00);
    }
    else if(InterruptNumber == Exti1)
    {
        MCUCR_Reg = MCUCR_Reg&~0x0C | (SensControl<<ISC10);
    }
    else if(InterruptNumber == Exti2)
    {
        MCUCSR_Reg = MCUCR_Reg&~0x40 | (SensControl<<ISC2);

    }
}

void EXTI_Enable(uint8_t InterruptNumber)
{
    if(InterruptNumber==Exti0)
    {
        SetBit(GICR_Reg,INT0);
    }
    else if (InterruptNumber==Exti1)
    {
        SetBit(GICR_Reg,INT1);
    }
    else if (InterruptNumber==Exti2)
    {
        SetBit(GICR_Reg,INT2);
    }
}

void EXTI_Disable(uint8_t InterruptNumber)
{
    if(InterruptNumber==Exti0)
    {
        ClearBit(GICR_Reg,INT0);
    }
    else if (InterruptNumber==Exti1)
    {
        ClearBit(GICR_Reg,INT1);
    }
    else if (InterruptNumber==Exti2)
    {
        ClearBit(GICR_Reg,INT2);
    }
}
static void (*GINT0)(void)=NULL;
static void (*GINT1)(void)=NULL;
static void (*GINT2)(void)=NULL;

/*CallBacks*/
void EXTI_CallBackFunction(uint8_t InterruptNumber , void (*PF)(void))
{
    if(PF==NULL)
    {
        return  ; 
    }
    if(InterruptNumber==Exti0)
    {
        GINT0=PF;
    }
    else if(InterruptNumber==Exti1)
    {
        GINT1=PF;
    }
    else if(InterruptNumber==Exti2)
    {
        GINT2=PF;
    }
}

void __vector_1() __attribute__((signal));
void __vector_1()
{
    if(GINT0!=NULL)
    {
        GINT0();
    }
}
void __vector_2() __attribute__((signal));
void __vector_2()
{
    if(GINT1!=NULL)
    {
        GINT1();
    }
}
void __vector_3() __attribute__((signal));
void __vector_3()
{
    if(GINT2!=NULL)
    {
        GINT2();
    }
}
