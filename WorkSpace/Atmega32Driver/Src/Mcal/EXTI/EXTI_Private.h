/**
 * @file EXTI_Private.h
 * @brief 
 * @author Hisham Ahmed (Hisham.ah.hamed@gmail.com)
 * @date 2026-10-06
 * @version 0.1
 * @copyright Copyright (c) 2026 Gestell. All rights reserved.
 */
#ifndef _MCAL_EXTI_EXTI_PRIVATE_H
#define _MCAL_EXTI_EXTI_PRIVATE_H
typedef enum
{
    /*MCUCR*/
    ISC00,
    ISC01,
    ISC10,
    ISC11,
    /*MCUCSR*/
    ISC2=6,
    /*GICR */
    INT2 = 5,
    INT0,
    INT1,
    /*GIFR */
    INTF2 = 5,
    INTF0,
    INTF1

}Exti_BitName_t;
/*Options*/
typedef enum 
{
    Exti_LowLevel,
    Exti_AnyLogic,
    Exti_Falling,
    Exti_Rising,

}Exti_SensControl_t;

typedef  enum 
{
    Exti0,
    Exti1,
    Exti2,
}Exti_Numbers_t;

#endif// _MCAL_EXTI_EXTI_PRIVATE_H
