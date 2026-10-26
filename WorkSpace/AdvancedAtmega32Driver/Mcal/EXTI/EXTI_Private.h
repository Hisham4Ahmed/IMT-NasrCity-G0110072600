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

// 76543210
// 00000000
// 00000001
// 00000010
// 00000011
// 76543210
// 00000000
// 00000100
// 76543210
// 0100 0000
// typedef enum
// {
//     Exti0_LowLevel =0x00,
//     Exti0_AnyLogic =0x01 ,
//     Exti0_Falling  =0x02,
//     Exti0_Rising   =0x03,  


//     Exti1_LowLevel = 0x00,
//     Exti1_AnyLogic = 0x04,
//     Exti1_Falling  = 0x08,
//     Exti1_Rising   = 0x0C,

//     Exti2_Falling  = 0x00,
//     Exti2_Rising   = 0x40,

// }Exti_EventType_t;


typedef  enum 
{
    Exti0,
    Exti1,
    Exti2,
}Exti_Numbers_t;

#endif// _MCAL_EXTI_EXTI_PRIVATE_H
