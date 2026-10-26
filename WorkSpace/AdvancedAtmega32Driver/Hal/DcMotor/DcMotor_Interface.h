
#ifndef DCMOTOR_INTERFACE
#define DCMOTOR_INTERFACE

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

#endif /* DCMOTOR_INTERFACE */
