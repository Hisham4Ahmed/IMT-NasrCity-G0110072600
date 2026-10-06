#ifndef _MCAL_ADC_ADC_PRIVATE_H
#define _MCAL_ADC_ADC_PRIVATE_H


typedef enum 
{
    // ADMUX
    MUX0,
    MUX1,
    MUX2,
    MUX3,
    MUX4,
    ADLAR,
    REFS0,
    REFS1,
    // ADCSRA
    ADPS0=0,
    ADPS1,        
    ADPS2,
    ADIE,
    ADIF,
    ADATE,
    ADSC,        
    ADEN,
    // SFIOR
    ADTS0=5,
    ADTS1,
    ADTS2,
}Adc_BitName_t;

typedef enum
{
    Adc_FreeRunning=0x00,
    Adc_AnalogComparator=0x20,
    Adc_EXTI0=0x40,
    Adc_CTC0=0x60,
    Adc_OVF0=0x80,
    Adc_CTC1=0xA0,
    Adc_OVF1=0xC0,
    Adc_ICU1=0xE0,
}Adc_TriggerSourceSelect_t;

typedef enum
{
    Adc_DivisionFactor2=1, 
    Adc_DivisionFactor4,  
    Adc_DivisionFactor8,  
    Adc_DivisionFactor16,  
    Adc_DivisionFactor32,  
    Adc_DivisionFactor64,  
    Adc_DivisionFactor128,  
}Adc_PrescalerSelect_t;

typedef enum
{
    Adc_InterruptDisable=0x00,
    Adc_InterruptEnable=0x08,
}Adc_InterruptState_t;
typedef enum
{
    Adc_SingleMode=0x00,
    Adc_AutoMode=0x20,
}Adc_Mode_t;
typedef enum
{
    Adc_Disable =0x00,
    Adc_Enable  =0x80,
}Adc_State_t;

typedef enum 
{
    Adc_Aref =0x00,
    Adc_Avcc =0x40,
    Adc_Internal=0xC0,
}Adc_ArefSelect_t;
typedef enum 
{
    Adc_RightAdjust=0x00,
    Adc_LeftAdjust=0x20,
}Adc_AdjustResult_t;
typedef enum 
{
    Adc_SingleEndedChannel0,
    Adc_SingleEndedChannel1,
    Adc_SingleEndedChannel2,
    Adc_SingleEndedChannel3,
    Adc_SingleEndedChannel4,
    Adc_SingleEndedChannel5,
    Adc_SingleEndedChannel6,
    Adc_SingleEndedChannel7,
}Adc_Channel_t;



typedef enum 
{
    Adc_TriggerSourceMask=0xE0,
    Adc_ChannelMask=0x1F,
}Adc_MaskingValue_t;

typedef enum 
{
    Adc_Uninitialized,
    Adc_Idle,
    Adc_Busy,
}Adc_DriverState;

typedef enum 
{
    Adc_Ok,
    Adc_NullPointerErr,
    Adc_InvalidChannelErr,
    Adc_NotInitializedErr,
    Adc_TimerOutErr,
}Adc_ErrorState_t;
#endif// _MCAL_ADC_ADC_PRIVATE_H
