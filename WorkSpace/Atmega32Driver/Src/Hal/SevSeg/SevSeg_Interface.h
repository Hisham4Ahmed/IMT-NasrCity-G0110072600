#ifndef SEVSEG_INTERFACE
#define SEVSEG_INTERFACE

#include <stdint.h>
#include "SevSeg_Private.h"
#include "SevSeg_Config.h"

void SSD_Init(uint8_t SSD_ID);

void SSD_DisplayNo(uint8_t SSD_ID , uint8_t Number);

#endif /* SEVSEG_INTERFACE */
