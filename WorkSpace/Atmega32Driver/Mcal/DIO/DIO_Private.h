/**
 * @file DIO_Private.h
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-08-22
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_


typedef enum 
{
    DIO_Input  = 0 ,
    DIO_Output = 1 ,
    DIO_AllOutput=0xFF,
}DIO_Direction_t;

typedef enum 
{
    DIO_Low , 
    DIO_High ,
    DIO_AllHigh=0xFF,
}DIO_OutputValue_t;

typedef enum 
{
    DIO_GroupA=1,
    DIO_GroupB,
    DIO_GroupC,
    DIO_GroupD,
    
}DIO_GroupName_t;

typedef enum 
{
    DIO_Pin0,
    DIO_Pin1,
    DIO_Pin2,
    DIO_Pin3,
    DIO_Pin4,
    DIO_Pin5,
    DIO_Pin6,
    DIO_Pin7,    
}DIO_PinNo_t;







#endif 

