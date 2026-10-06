/**
 * @file    Atmega32Registers.h
 * @brief   
 * @details 
 * @version {version}
 * @date    {date}
 * @copyright Copyright (c) {year} Gestell-Co. All rights reserved.
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-09-09
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#ifndef _MCAL_ATMEGA32REGISTERS_H
#define _MCAL_ATMEGA32REGISTERS_H
#include <stdint.h>
#define _SetAddress8bit(Addrress)   *((volatile uint8_t*)Addrress)
#define _SetAddress16bit(Addrress)  *((volatile uint16_t*)Addrress)
#define _SetAddress32bit(Addrress)  *((volatile uint32_t*)Addrress)


#define DDRA_Reg    _SetAddress8bit(0x3A)
#define PORTA_Reg   _SetAddress8bit(0x3B)
#define PINA_Reg    *((volatile uint8_t*)0x39)

#define DDRB_Reg    *((volatile uint8_t*)0x37)
#define PORTB_Reg   *((volatile uint8_t*)0x38)
#define PINB_Reg    *((volatile uint8_t*)0x36)

#define DDRC_Reg    *((volatile uint8_t*)0x34)
#define PORTC_Reg   *((volatile uint8_t*)0x35)
#define PINC_Reg    *((volatile uint8_t*)0x33)

#define DDRD_Reg    *((volatile uint8_t*)0x31)
#define PORTD_Reg   *((volatile uint8_t*)0x32)
#define PIND_Reg    *((volatile uint8_t*)0x30)

#define SREG_Reg    *((volatile uint8_t*)0x5F)

#define MCUCR_Reg    *((volatile uint8_t*)0x55)
#define MCUCSR_Reg   *((volatile uint8_t*)0x54)
#define GICR_Reg     *((volatile uint8_t*)0x5B)
#define GIFR_Reg     *((volatile uint8_t*)0x5A)


#define ADMUX_Reg    *((volatile uint8_t*)0x27)   
#define ADCSRA_Reg   *((volatile uint8_t*)0x26)
#define ADCH_Reg     *((volatile uint8_t*)0x25)
#define ADCL_Reg     *((volatile uint8_t*)0x24)
#define ADCData_Reg  *((volatile uint16_t*)0x24)
#define SFIOR_Reg    *((volatile uint8_t*)0x50)

#define TCCR0_Reg    *((volatile uint8_t*)0x53)
#define TCNT0_Reg    *((volatile uint8_t*)0x52)
#define OCR0_Reg     *((volatile uint8_t*)0x5C)
#define TIMSk_Reg    *((volatile uint8_t*)0x59)
#define TIFR_Reg     *((volatile uint8_t*)0x58)

#endif// _MCAL_ATMEGA32REGISTERS_H
