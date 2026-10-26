/**
 * @file Btn_Program.c
 * @brief 
 * @author Hisham Ahmed (Hisham.ah.hamed@gmail.com)
 * @date 2026-09-23
 * @version 0.1
 * @copyright Copyright (c) 2026 Gestell. All rights reserved.
 */

#include "../../Common/Config.h"

#if Button_Driver
#include "Btn_Interface.h"
void BTN_Init(uint8_t BtnGroup,uint8_t BtnPin,uint8_t BtnConnection)
{
    DIO_DirectionSelectForPin(BtnGroup,BtnPin,DIO_Input);
    if(BtnConnection==Btn_InternalPullup)
    {
        DIO_InternalPullUpControl(BtnGroup,BtnPin,Enable);
    }
    else
    {
        DIO_InternalPullUpControl(BtnGroup,BtnPin,Disable);
    }

}

uint8_t BTN_GetState(uint8_t BtnGroup,uint8_t BtnPin,uint8_t BtnConnection)
{
    uint8_t BtnState=0;    
    DIO_ReadInputForPin(BtnGroup,BtnPin,&BtnState);
    return BtnState;
}



#endif// Button_Driver