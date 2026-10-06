/**
 * @file Atmega32Registers.h
 * @brief 
 * @author Hisham Ahmed (Hisham.ah.hamed@gmail.com)
 * @date 2026-10-06
 * @version 0.1
 * @copyright Copyright (c) 2026 Gestell. All rights reserved.
 */
#ifndef ATMEGA32REGISTERS_H
#define ATMEGA32REGISTERS_H
#include <stdint.h>
#define _SetAddress8bit(Addrress)   *((volatile uint8_t*)Addrress)
#define _SetAddress16bit(Addrress)  *((volatile uint16_t*)Addrress)
#define _SetAddress32bit(Addrress)  *((volatile uint32_t*)Addrress)


#define DDRA_Reg    _SetAddress8bit(0x3A)
#define PORTA_Reg   _SetAddress8bit(0x3B)
#define PINA_Reg    _SetAddress8bit(0x39)

#define DDRB_Reg    _SetAddress8bit(0x37)
#define PORTB_Reg   _SetAddress8bit(0x38)
#define PINB_Reg    _SetAddress8bit(0x36)

#define DDRC_Reg    _SetAddress8bit(0x34)
#define PORTC_Reg   _SetAddress8bit(0x35)
#define PINC_Reg    _SetAddress8bit(0x33)

#define DDRD_Reg    _SetAddress8bit(0x31)
#define PORTD_Reg   _SetAddress8bit(0x32)
#define PIND_Reg    _SetAddress8bit(0x30)

#define SREG_Reg    _SetAddress8bit(0x5F)

#define MCUCR_Reg    _SetAddress8bit(0x55)
#define MCUCSR_Reg   _SetAddress8bit(0x54)
#define GICR_Reg     _SetAddress8bit(0x5B)
#define GIFR_Reg     _SetAddress8bit(0x5A)


#define ADMUX_Reg    _SetAddress8bit(0x27)   
#define ADCSRA_Reg   _SetAddress8bit(0x26)
#define ADCH_Reg     _SetAddress8bit(0x25)
#define ADCL_Reg     _SetAddress8bit(0x24)
#define ADCData_Reg  _SetAddress16bit(0x24)
#define SFIOR_Reg    _SetAddress8bit(0x50)

#define TCCR0_Reg    _SetAddress8bit(0x53)
#define TCNT0_Reg    _SetAddress8bit(0x52)
#define OCR0_Reg     _SetAddress8bit(0x5C)

#define TCCR2_Reg    _SetAddress8bit(0x45)
#define TCNT2_Reg    _SetAddress8bit(0x44)
#define OCR2_Reg     _SetAddress8bit(0x43)

#define TIMSk_Reg    _SetAddress8bit(0x59)
#define TIFR_Reg     _SetAddress8bit(0x58)

#endif /*ATMEGA32REGISTERS_H */ 
