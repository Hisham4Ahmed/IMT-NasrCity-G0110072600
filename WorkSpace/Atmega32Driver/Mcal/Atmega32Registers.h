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
#define DDRA_Reg    *((volatile uint8_t*)0x3A)
#define PORTA_Reg   *((volatile uint8_t*)0x3B)
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

#endif// _MCAL_ATMEGA32REGISTERS_H
