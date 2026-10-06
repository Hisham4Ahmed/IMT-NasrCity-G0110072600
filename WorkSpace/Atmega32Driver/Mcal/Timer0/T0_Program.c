
#include "T0_Interface.h"



#if T0_Normal 
static void(*NormalPF)(void)=NULL;
static T0_PreloadValue = T0_InitPreloadValue;
void T0_NormalInit()
{
    // TCCR0
    //! 1. Wave Generation Mode as Normal Mode 
    //! 2. Select Ouput Compare Matec Disconnect 
    //! 3. Clock Select -> Prescaller 
    TCCR0_Reg = T0_NormalMode|OC0_Disconnect|T0_ClockSelect ;  
    // TCNT -> InialValue Preload 
    TCNT0_Reg = T0_InitPreloadValue;
    // TIMSK -> Enable for OVF Interrupt 
    SetBit(TIMSk_Reg,TOIE0);
}
void T0_SetPreLoad(uint8_t PreloadValue)
{
     TCNT0_Reg = PreloadValue;
     T0_PreloadValue = PreloadValue;
}
void T0_NormalCallBack(void(*PF)(void))
{
    if(PF!=NULL)
    {
        NormalPF=PF;
    }      
}
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
    static uint32_t count =  0 ;
    count++;
    if(count==T0_NoOfOVFCount)
    {
        // Action 
        if(NormalPF!=NULL)
        {
            NormalPF();
        }
        // Clear Count 
        count = 0 ; 
        // Update Preload  
        TCNT0_Reg = T0_PreloadValue;
    }
}
#endif

#if T0_CTC
void T0_CTCInit();
void T0_SetCompareValue(uint8_t CompareValue);
void T0_CTCCallBack(void(*PF)(void));
#endif

#if T0_PWM
    void T0_PwmInit()
    {
        //! 1. Select PWM Mode 
        //! 2. Select Action (Inverting / Non-Inverting)
        //! 3. Clock Select 
        TCCR0_Reg = T0_PWMMode|T0_PWMAction|T0_ClockSelect ; 
        
    }
    void T0_SetDutyCycle(uint8_t DutyCyclePre)
    {
        if(DutyCyclePre<=100)
        {
            if(T0_PWMAction==OC0_NonInverting)
            {
                // Comparevalue (ORC0) = OVFValue*(DutyCycle/100)
                OCR0_Reg = (256* (uint16_t)DutyCyclePre)/100;
            }
            else if (T0_PWMAction==OC0_Inverting)
            {
                // Comparevalue (ORC0) = OVFValue*(1-(DutyCycle/100))
                // Comparevalue (ORC0) = OVFValue  - OVFValue*(DutyCycle/100); 
                OCR0_Reg = 256 -  (256* (uint16_t)DutyCyclePre)/100;

            }
        }
    }
#endif
