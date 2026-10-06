/**
 * @file ADC_Program.c
 * @brief 
 * @author Hisham Ahmed (Hisham.ah.hamed@gmail.com)
 * @date 2026-09-28
 * @version 0.1
 * @copyright Copyright (c) 2026 Gestell. All rights reserved.
 */

#include "ADC_Interface.h"
static uint8_t ADC_State = Adc_Uninitialized;

void ADC_Init()
{
    /* Pseudo-code & Steps 
     * //! Configure Voltage reference & Result Adjust
     * //! Configure Control and Status Register for enable ,  mode ,interrupts , prescaller 
     * //! Configure Trigger Source if Auto Mode Selected  
    */
   if(ADC_State!=Adc_Uninitialized)
   {
     return ;
   }
   /* 
    * //! Configuration ADMUX : Voltage & Adjust 
    * //! BitMask => (Reg = Reg&~Mask | Value)
    * //! ADMUX = > 1 1 1 0 0 0 0 0 
    */
    ADMUX_Reg = Adc_VrefSelection | Adc_AdjustSelection ; 
    /* 
    * //! Configuration ADCSRA : Enable & Mode & Interrupts & Prescaller 
    */
   ADCSRA_Reg = Adc_InitState|Adc_ModeSelect|Adc_InterrupState|Adc_DivisionFactorSelection;
    /* 
    * //! Configuration SFIOR : Configure Trigger Source if Auto Mode Selected
    * //! SFIOR -> 7 6 5 -> another use in another perpherial 
    * //! BitMask => (Reg = Reg&~Mask | Value)
    * //! Adc_TriggerSourceMask = 1 1 1 0 0 0 0 0 -> 0x E0
    */
    #if Adc_ModeSelect==Adc_AutoMode
    SFIOR_Reg =  (SFIOR_Reg & ~ Adc_TriggerSourceMask) | Adc_TriggerSource ; 
    #endif
    ADC_State=Adc_Idle;

}
void ADC_DeInit()
{
    /* pseudo-code & Steps:
     * //! 1. Clear the ADC Conversion Complete Flag (ADIF)
     * //! 2. Disable the ADC Interrupt 
     * //! 3. Disable the ADC Peripheral 
     * //! 4. Reset Driver State to Uninitialized*/
}
void ADC_Enable()
{
    SetBit(ADCSRA_Reg,ADEN);
}
void ADC_Disable()
{
    ClearBit(ADCSRA_Reg,ADEN);
}
void ADC_EnableInterrupt()
{
    SetBit(ADCSRA_Reg,ADIE);
}
void ADC_DisableInterrupt()
{
    ClearBit(ADCSRA_Reg,ADIE);
}

static void ADC_SelectChannel(uint8_t Channel)
{
    /* pseudo-code & Steps:
     * //! 1. Clear Channel Bits in ADMUX (4:0) => (ADMUX_Reg&~Adc_ChannelMask)
     * //! 2. Make Sure the Channel Var with in Range (31:0)  (Channel & Adc_ChannelMask)
     * //! 3. Apply the New Channel 
     * */
    ADMUX_Reg = (ADMUX_Reg&~Adc_ChannelMask)| (Channel & Adc_ChannelMask);
}
uint8_t ADC_Read(uint8_t Channel,uint16_t *DigitalValue, uint32_t MaxTimeOut)
{
     /* pseudo-code & Steps:
     * //! 1. Validate Pointer  & Validate Range & Driver State 
     * //! 2. Select Channel 
     * //! 3. Start Conversion 
     * //! 3. Update the Driver State to Busy  
     * //! 3. Start Conversion 
     * 
     * */  
    uint32_t LocalTimeOut = 0 ;
    if (DigitalValue==NULL)
    {
        return Adc_NullPointerErr;
    }
    if(Channel> Adc_SingleEndedChannel7)
    {
        return Adc_InvalidChannelErr;
    }
    if(ADC_State== Adc_Uninitialized)
    {
        return Adc_NotInitializedErr;
    }
    ADC_SelectChannel(Channel);
    SetBit(ADCSRA_Reg,ADSC);
    ADC_State = Adc_Busy;
    // waiting  until conversion Finish -> Flag Set 
    while(ReadBit(ADCSRA_Reg,ADIF)==0)
    {
        if(LocalTimeOut>=MaxTimeOut)
        {
            ADC_State = Adc_Idle;
            return Adc_TimerOutErr;
        }
        LocalTimeOut++;
    }
    // Clear Flag Manual 
    SetBit(ADCSRA_Reg,ADIF);
    // Return Value 
    *DigitalValue = ADCData_Reg;
    ADC_State = Adc_Idle;
    return (Adc_Ok);

}

uint8_t ADC_GetStatus()
{
    return ADC_State;
}
