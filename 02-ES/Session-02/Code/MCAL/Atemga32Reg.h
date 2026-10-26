#ifndef  _ATMEGA32Reg_H
#define  _ATMEGA32Reg_H

#define SREG_Reg    *((volatile uint8_t*)0x5F)
/*Stack Pointer */
#define SPH_Reg     *((volatile uint8_t*)0x5E)
#define SPL_Reg     *((volatile uint8_t*)0x5D)
#define SP_Reg      *((volatile uint16_t*)0x5D)

#define OSCCAL_Reg  *((volatile uint16_t*)0x51)





#endif 