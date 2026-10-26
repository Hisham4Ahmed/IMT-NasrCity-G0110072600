
#include "DcMotor_Interface.h"


void DC_Init(Dc_config_t *Config)
{
    if(Config!=NULL)
    {
        if(Config->ConnectionType==Dc_WithoutHBridge)
        {
            DIO_DirectionSelectForPin(Config->Dc_M1Group,Config->Dc_M1Pin,DIO_Output);
        }
        else if (Config->ConnectionType==Dc_WithHBridge)
        {
            DIO_DirectionSelectForPin(Config->Dc_M1Group,Config->Dc_M1Pin,DIO_Output);
            DIO_DirectionSelectForPin(Config->Dc_M2Group,Config->Dc_M2Pin,DIO_Output);
        }
        else
        {

        }
    }
}
/*API for On Off Control Only*/
void DC_On(Dc_config_t *Config)
{
    if(Config!=NULL)
    {
        if(Config->ConnectionType==Dc_WithoutHBridge)
        {
            DIO_WriteForPin(Config->Dc_M1Group,Config->Dc_M1Pin,DIO_High);
        }
        else
        {

        }
    }
}
void DC_Off(Dc_config_t *Config)
{
    if(Config!=NULL)
    {
        if(Config->ConnectionType==Dc_WithoutHBridge)
        {
            DIO_WriteForPin(Config->Dc_M1Group,Config->Dc_M1Pin,DIO_Low);
        }
        else if (Config->ConnectionType == Dc_WithHBridge)
        {
            DIO_WriteForPin(Config->Dc_M1Group,Config->Dc_M1Pin,DIO_Low);
            DIO_WriteForPin(Config->Dc_M2Group,Config->Dc_M2Pin,DIO_Low);
        }
        else
        {

        }
    }
}
/*API for On Off&Direction Control */
void DC_OnCW(Dc_config_t *Config)
{
    if(Config!=NULL)
    {
        if(Config->ConnectionType==Dc_WithHBridge)
        {
            DIO_WriteForPin(Config->Dc_M1Group,Config->Dc_M1Pin,DIO_High);
            DIO_WriteForPin(Config->Dc_M2Group,Config->Dc_M2Pin,DIO_Low);
        }
        else
        {

        }
    }
}
void DC_OnCCW(Dc_config_t *Config)
{
    if(Config!=NULL)
    {
        if(Config->ConnectionType==Dc_WithHBridge)
        {
            DIO_WriteForPin(Config->Dc_M1Group,Config->Dc_M1Pin,DIO_Low);
            DIO_WriteForPin(Config->Dc_M2Group,Config->Dc_M2Pin,DIO_High);
        }
        else
        {

        }
    }
}