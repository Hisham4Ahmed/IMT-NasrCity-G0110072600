
#ifndef _HAL_DCMOTOR_DCMOTOR_INTERFACE_H
#define _HAL_DCMOTOR_DCMOTOR_INTERFACE_H

#include "../../Mcal/DIO/DIO_Interface.h"
#include "DcMotor_Private.h"
#include "DcMotor_Config.h"

void DC_Init(Dc_config_t *Config);
/*API for On Off Control Only*/
void DC_On(Dc_config_t *Config);
void DC_Off(Dc_config_t *Config);
/*API for On Off&Direction Control */
void DC_OnCW(Dc_config_t *Config);
void DC_OnCCW(Dc_config_t *Config);

#endif// _HAL_DCMOTOR_DCMOTOR_INTERFACE_H
