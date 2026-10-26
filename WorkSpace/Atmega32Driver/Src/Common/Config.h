/**
 * @file    Config.h
 * @brief   Shared configuration for the ATmega32 driver project.
 * @author  Hisham Ahmed (Hisham.ah.hamed@gmail.com)
 * @date    2026-10-06
 * @version 0.1
 * @copyright Copyright (c) 2026 Gestell-Co. All rights reserved.
 */
#ifndef _COMMON_CONFIG_H
#define _COMMON_CONFIG_H

#include "Definition.h"

/* ATmega32 project clock; keep this guarded for build-level overrides. */
#ifndef F_CPU
#define F_CPU 8000000UL
#endif// _COMMON_CONFIG_H
/*MCAL*/
/* Driver switches used by the current project. */
#define ADC_Driver          Enable
#define DIO_Driver          Enable
#define EXTI_Driver         Enable
#define GIE_Driver          Enable
#define InternalEEPROM      Enable
#define SPI_Driver          Enable 
#define Timer0_Driver       Enable
#define Timer1_Driver       Enable
#define Timer2_Driver       Enable
#define TWI_Driver          Enable
#define Usart_Driver        Enable

/*HAL*/
#define Button_Driver       Enable
#define Buzzer_Driver       Enable
#define DcMotor_Driver      Enable
#define Kpd_Driver          Enable
#define Lcd_Driver          Enable
#define Led_Driver          Enable
#define SevSeg_Driver       Enable


#if Timer0_Driver
/* Select one Timer0 mode; the current application uses overflow mode. */
#define T0_Normal     Enable
#define T0_CTC        Enable
#define T0_PWM        Enable
#endif//  Timer0_Driver



#if Timer2_Driver
/* Timer2 driver files are present, but its configuration/API is not implemented. */
#define T2_Normal     Enable
#define T2_CTC        Enable
#define T2_PWM        Enable
#endif//  Timer2_Driver


#endif//     _COMMON_CONFIG_H
