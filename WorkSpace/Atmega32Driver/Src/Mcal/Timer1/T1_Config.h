#ifndef _SRC_MCAL_TIMER1_T1_CONFIG_H
#define _SRC_MCAL_TIMER1_T1_CONFIG_H


/*
 T1_Disable,
    T1_NoPrescaller,
    T1_Prescaller_8,
    T1_Prescaller_64,
    T1_Prescaller_256,
    T1_Prescaller_1024,
    T1_ExternalFalling,
    T1_ExternalRising

*/
   
#define T1_ClockSelectInit      T1_Prescaller_64

/*
T1_ICU_Falling  
T1_ICU_Rising  
*/
#define  ICU_EdgeSelectInit     T1_ICU_Rising

#endif// _SRC_MCAL_TIMER1_T1_CONFIG_H
