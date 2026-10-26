
#include "EXTI_Interface.h"
// void EXTI_Init(uint8_t InterruptNumber , uint8_t SensControl)
//{
//    if(InterruptNumber==Exti0)
//    {
//        if(SensControl==Exti_LowLevel)
//        {
//            ClearBit(MCUCR_Reg,ISC00);
//            ClearBit(MCUCR_Reg,ISC00);
//        }
//        else if (SensControl==Exti_AnyLogic)
//        {
//            SetBit(MCUCR_Reg,ISC00);
//            ClearBit(MCUCR_Reg,ISC01);
//        }
//
//        else if (SensControl==Exti_Falling)
//        {
//            ClearBit(MCUCR_Reg,ISC00);
//            SetBit(MCUCR_Reg,ISC01);
//        }
//
//        else if (SensControl==Exti_Rising)
//        {
//            SetBit(MCUCR_Reg,ISC00);
//            SetBit(MCUCR_Reg,ISC01);
//        }
//    }
//    else if(InterruptNumber==Exti1)
//    {
//        if(SensControl==Exti_LowLevel)
//        {
//            ClearBit(MCUCR_Reg,ISC10);
//            ClearBit(MCUCR_Reg,ISC10);
//        }
//        else if (SensControl==Exti_AnyLogic)
//        {
//            SetBit(MCUCR_Reg,ISC10);
//            ClearBit(MCUCR_Reg,ISC11);
//        }
//
//        else if (SensControl==Exti_Falling)
//        {
//            ClearBit(MCUCR_Reg,ISC10);
//            SetBit(MCUCR_Reg,ISC11);
//        }
//
//        else if (SensControl==Exti_Rising)
//        {
//            SetBit(MCUCR_Reg,ISC10);
//            SetBit(MCUCR_Reg,ISC11);
//        }
//    }
//    else if(InterruptNumber==Exti2)
//    {
//        if (SensControl==Exti_Falling)
//        {
//            ClearBit(MCUCSR_Reg,ISC2);
//        }
//
//        else if (SensControl==Exti_Rising)
//        {
//            SetBit(MCUCSR_Reg,ISC2);
//        }
//    }
//}

// MCUCR - > 
// 7 6 5 4 3 2 1 0 

// Mask -> 0 0 0 0 0 0 1 1 
// Mask -> 0 0 0 0 1 1 0 0 
// Mask -> 0 1 0 0 0 0 0 0   
// // EXTI_Init(Exti0,Exti0_AnyLogic);
// EXTI_Init(Exti1,Exti1_Rising);

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
