#ifndef _MCAL_ADC_ADC_CONFIG_H
#define _MCAL_ADC_ADC_CONFIG_H

#include "ADC_Private.h"


#define Adc_InitState  Adc_Enable
/**
 * @def    Adc_VrefSelection
 * @brief  Options:
 *          - Adc_Aref
 *          - Adc_Avcc
 *          - Adc_Internal
*/
#define Adc_VrefSelection Adc_Internal 

#define Adc_AdjustSelection Adc_LeftAdjust 
/**
 *  Adc_DivisionFactor2=1, 
    Adc_DivisionFactor4,  
    Adc_DivisionFactor8,  
    Adc_DivisionFactor16,  
    Adc_DivisionFactor32,  
    Adc_DivisionFactor64,  
    Adc_DivisionFactor128,  
 */
#define Adc_DivisionFactorSelection  Adc_DivisionFactor8

#define Adc_ModeSelect Adc_SingleMode 

#if Adc_ModeSelect==Adc_AutoMode
#define Adc_TriggerSource Adc_FreeRunning
#endif// _MCAL_ADC_ADC_CONFIG_H

#define Adc_InterrupState  Adc_InterruptDisable

#endif// _MCAL_ADC_ADC_CONFIG_H
