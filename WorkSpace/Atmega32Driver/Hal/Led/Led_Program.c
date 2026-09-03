#include "Led_Interface.h"

void Led_Init(uint8_t LedGroup,uint8_t LedPin)
{
    DIO_DirectionSelectForPin(LedGroup,LedPin,DIO_High);
}

void Led_On(uint8_t LedGroup,uint8_t LedPin,uint8_t ConnectionType)
{
    DIO_WriteForPin(DIO_GroupB,DIO_Pin3,DIO_Low);
    if(ConnectionType==Led_SourceConnection)
    {
        DIO_WriteForPin(LedGroup,LedPin,DIO_High);
    }
    else if (ConnectionType==Led_SinkConnection)
    {
        DIO_WriteForPin(LedGroup,LedPin,DIO_Low);
    }
    else
    {

    }
    DIO_WriteForPin(DIO_GroupB,DIO_Pin3,DIO_High);

}

void Led_Off(uint8_t LedGroup,uint8_t LedPin,uint8_t ConnectionType)
{
    if(ConnectionType==Led_SourceConnection)
    {
        DIO_WriteForPin(LedGroup,LedPin,DIO_Low);
    }
    else if (ConnectionType==Led_SinkConnection)
    {
        DIO_WriteForPin(LedGroup,LedPin,DIO_High);
    }
    else
    {

    }
}

void Led_Toggle(uint8_t LedGroup,uint8_t LedPin)
{
    DIO_ToggleForPin(LedGroup,LedPin);
}