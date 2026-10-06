
#include "T0_Interface.h"



#if T2_Normal 
static void(*NormalPF)(void)=NULL;
static T2_PreloadValue = T2_InitPreloadValue;
void T2_NormalInit()
{
    // TCCR0
    //! 1. Wave Generation Mode as Normal Mode 
    //! 2. Select Ouput Compare Matec Disconnect 
    //! 3. Clock Select -> Prescaller 
    TCCR2_Reg = T0_NormalMode|OC0_Disconnect|T0_ClockSelect ;  
    // TCNT -> InialValue Preload 
    TCNT2_Reg = T0_InitPreloadValue;
    // TIMSK -> Enable for OVF Interrupt 
    SetBit(TIMSk_Reg,TOIE0);
}
void T0_SetPreLoad(uint8_t PreloadValue)
{
     TCNT0_Reg = PreloadValue;
     T0_PreloadValue = PreloadValue;
}
void T2_NormalCallBack(void(*PF)(void))
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
    if(count==T2_NoOfOVFCount)
    {
        // Action 
        if(NormalPF!=NULL)
        {
            NormalPF();
        }
        // Clear Count 
        count = 0 ; 
        // Update Preload  
        TCNT2_Reg = T2_PreloadValue;
    }
}
#endif

#if T2_CTC
void T2_CTCInit();
void T2_SetCompareValue(uint8_t CompareValue);
void T2_CTCCallBack(void(*PF)(void));
#endif

#if T2_PWM
    void T2_PwmInit()
    {
        //! 1. Select PWM Mode 
        //! 2. Select Action (Inverting / Non-Inverting)
        //! 3. Clock Select 
        TCCR2_Reg = T2_PWMMode|T2_PWMAction|T2_ClockSelect ; 
        
    }
    void T2_SetDutyCycle(uint8_t DutyCyclePre)
    {
        if(DutyCyclePre<=100)
        {
            if(T2_PWMAction==OC2_NonInverting)
            {
                // Comparevalue (ORC0) = OVFValue*(DutyCycle/100)
                OCR2_Reg = (256* (uint16_t)DutyCyclePre)/100;
            }
            else if (T2_PWMAction==OC2_Inverting)
            {
                // Comparevalue (ORC0) = OVFValue*(1-(DutyCycle/100))
                // Comparevalue (ORC0) = OVFValue  - OVFValue*(DutyCycle/100); 
                OCR2_Reg = 256 -  (256* (uint16_t)DutyCyclePre)/100;

            }
        }
    }
#endif
