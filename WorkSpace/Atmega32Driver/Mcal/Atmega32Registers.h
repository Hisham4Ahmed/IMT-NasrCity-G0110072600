/*
 * Atmega32Registers.h
 *
 *  Created on: Aug 22, 2026
 *      Author: hesham
 */

#ifndef MCAL_ATMEGA32REGISTERS_H_
#define MCAL_ATMEGA32REGISTERS_H_
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


#endif /* MCAL_ATMEGA32REGISTERS_H_ */
