/**
 * @file DIO_Program.c
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-08-22
 * 
 * @copyright Copyright (c) 2026
 * 
 */


#include "DIO_Interface.h"
void DIO_DirectionSelectForPin(uint8_t GroupName ,uint8_t PinNo ,uint8_t DirectionState )
{
    if(PinNo<=DIO_Pin7)
        {
            if(DirectionState==DIO_Output)
            {
                switch(GroupName)
                {
                    case DIO_GroupA: SetBit(DDRA_Reg,PinNo);break;
                    case DIO_GroupB: SetBit(DDRB_Reg,PinNo);break;
                    case DIO_GroupC: SetBit(DDRC_Reg,PinNo);break;
                    case DIO_GroupD: SetBit(DDRD_Reg,PinNo);break;
                    default : break; /*Error Code Wrong GroupName*/
                }
            }
            else if (DirectionState==DIO_Input)
            {
                switch(GroupName)
                {
                    case DIO_GroupA: ClearBit(DDRA_Reg,PinNo);break;
                    case DIO_GroupB: ClearBit(DDRB_Reg,PinNo);break;
                    case DIO_GroupC: ClearBit(DDRC_Reg,PinNo);break;
                    case DIO_GroupD: ClearBit(DDRD_Reg,PinNo);break;
                    default : break; /*Error Code Wrong GroupName*/
                }
            }
            else{
                // Error Code 
            }
        }
}

void DIO_DirectionSelectForGroup(uint8_t GroupName ,uint8_t DirectionState )
{
    switch(GroupName)
    {
        case DIO_GroupA: DDRA_Reg=DirectionState;break;
        case DIO_GroupB: DDRB_Reg=DirectionState;break;
        case DIO_GroupC: DDRC_Reg=DirectionState;break;
        case DIO_GroupD: DDRD_Reg=DirectionState;break;
        default :  break;/*ErrorCode wrong Group*/
    }
}
void DIO_WriteForGroup(uint8_t GroupName ,uint8_t OutputValue )
{

    switch(GroupName)
    {
        case DIO_GroupA: PORTA_Reg=OutputValue;break;
        case DIO_GroupB: PORTB_Reg=OutputValue;break;
        case DIO_GroupC: PORTC_Reg=OutputValue;break;
        case DIO_GroupD: PORTD_Reg=OutputValue;break;
        default : break;/*ErrorCode wrong Group*/
    }
}

void DIO_WriteForPin(uint8_t GroupName ,uint8_t PinNo ,uint8_t OutputValue )
{
    if (PinNo<=DIO_Pin7)
    {
        if(OutputValue==DIO_Low)
        {
            switch(GroupName)
            {
                case DIO_GroupA: ClearBit(PORTA_Reg,PinNo);break;
                case DIO_GroupB: ClearBit(PORTB_Reg,PinNo);break;
                case DIO_GroupC: ClearBit(PORTC_Reg,PinNo);break;
                case DIO_GroupD: ClearBit(PORTD_Reg,PinNo);break;
            }
        }
        else if(OutputValue==DIO_High)
        {
            switch(GroupName)
            {
                case DIO_GroupA: SetBit(PORTA_Reg,PinNo);break;
                case DIO_GroupB: SetBit(PORTB_Reg,PinNo);break;
                case DIO_GroupC: SetBit(PORTC_Reg,PinNo);break;
                case DIO_GroupD: SetBit(PORTD_Reg,PinNo);break;
            }
        }
    }
}


void DIO_ReadInputForPin(uint8_t GroupName ,uint8_t PinNo ,uint8_t *InputState )
{
    if(InputState!=NULL&&PinNo<=DIO_Pin7)
    {
        switch(GroupName)
        {
         case DIO_GroupA:*InputState=ReadBit(PINA_Reg,PinNo);break;
         case DIO_GroupB:*InputState=ReadBit(PINB_Reg,PinNo);break;
         case DIO_GroupC:*InputState=ReadBit(PINC_Reg,PinNo);break;
         case DIO_GroupD:*InputState=ReadBit(PIND_Reg,PinNo);break;            
        }
    }
}

void DIO_ReadInputForGroup(uint8_t GroupName ,uint8_t *InputState)
{
    if(InputState!=NULL)
    {
        switch(GroupName)
        {
            case DIO_GroupA : *InputState=PINA_Reg;break;
            case DIO_GroupB : *InputState=PINB_Reg;break;
            case DIO_GroupC : *InputState=PINC_Reg;break;
            case DIO_GroupD : *InputState=PIND_Reg;break;
        }
    }
}


void DIO_ToggleForPin(uint8_t GroupName ,uint8_t PinNo )
{
    if(PinNo<=DIO_Pin7)
    {
        switch(GroupName)
        {
            case DIO_GroupA: ToggleBit(PORTA_Reg,PinNo);break;
            case DIO_GroupB: ToggleBit(PORTB_Reg,PinNo);break;
            case DIO_GroupC: ToggleBit(PORTC_Reg,PinNo);break;
            case DIO_GroupD: ToggleBit(PORTD_Reg,PinNo);break;
        }
    }
}
void DIO_ToggleForGroup(uint8_t GroupName  )
{
        switch(GroupName)
        {                                   
            case DIO_GroupA: PORTA_Reg= ~PORTA_Reg;break;
            case DIO_GroupB: PORTB_Reg= ~PORTB_Reg;break;
            case DIO_GroupC: PORTC_Reg= ~PORTC_Reg;break;
            case DIO_GroupD: PORTD_Reg= ~PORTD_Reg;break;
        }
}
 /*Internal Pull Up */
void DIO_InternalPullUpControl(uint8_t GroupName ,uint8_t PinNo,uint8_t PullUpState)
{
    DIO_WriteForPin(GroupName,PinNo,PullUpState);        
}

