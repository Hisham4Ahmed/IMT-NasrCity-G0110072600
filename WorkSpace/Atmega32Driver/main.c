/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-09-09
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include <util/delay.h>
#include "Mcal/DIO/DIO_Interface.h"
#include "Hal/Led/Led_Interface.h"
#include "Hal/LCD/LCD_Interface.h"
#include "Hal/KPD/KPD_Interface.h"
#include "Hal/DcMotor/DcMotor_Interface.h"
void main()
{
    Dc_config_t MyMotor1 = 
    {
        .ConnectionType = Dc_WithoutHBridge,
        .Dc_M1Group = DIO_GroupA,
        .Dc_M1Pin =DIO_Pin0,
    };
    Dc_config_t MyMotor2 = 
    {
        .ConnectionType = Dc_WithHBridge,
        .Dc_M1Group = DIO_GroupD,
        .Dc_M1Pin =DIO_Pin0,
        .Dc_M2Group = DIO_GroupC,
        .Dc_M2Pin =DIO_Pin6,
    };
    DC_Init(&MyMotor1);
    DC_Init(&MyMotor2);
    while(1)
    {
        DC_On(&MyMotor1);
        DC_OnCW(&MyMotor2);
        _delay_ms(5000);
        DC_Off(&MyMotor1);
        DC_Off(&MyMotor2);
        _delay_ms(5000);
        DC_On(&MyMotor1);
        DC_OnCCW(&MyMotor2);
        _delay_ms(5000);
        DC_Off(&MyMotor1);
        DC_Off(&MyMotor2);
        _delay_ms(5000);
    }
	
}



