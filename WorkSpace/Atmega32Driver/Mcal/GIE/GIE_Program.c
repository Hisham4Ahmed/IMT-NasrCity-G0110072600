/**
 * @file GIE_Program.c
 * @brief 
 * @author Hisham Ahmed (Hisham.ah.hamed@gmail.com)
 * @date 2026-09-18
 * @version 0.1
 * @copyright Copyright (c) 2026 Gestell. All rights reserved.
 */



#include "GIE_Interface.h"

void GIE_Enable()
{
    SetBit(SREG_Reg,7);
}

void GIE_Disable()
{
    ClearBit(SREG_Reg,7);
}

