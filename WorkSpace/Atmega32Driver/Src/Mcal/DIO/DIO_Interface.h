/**
 * @file DIO_Interface.h
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-08-22
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_



#include <stdint.h>
#include "../../Common/BitMath.h"
#include "../../Common/Definition.h"
#include "../Atmega32Registers.h"

#include "DIO_Private.h"
#include "DIO_Config.h"

 /*Direction*/


/**
 * @fn      DIO_DirectionSelectForPin
 * @brief   This function is used to set the direction of a specific pin in a specific group (port) of the microcontroller. 
 *          The direction can be set to either input or output based on the provided DirectionState parameter.
 * @author Hisham Ahmed (Hisham.ah.hamed@gmail.com)
 * @date 2026-10-06
 * @version 0.1
 * @copyright Copyright (c) 2026 Gestell. All rights reserved.
 * @param[in] GroupName  
 * @param[in] PinNo 
 * @param[in] DirectionState 
 */
void DIO_DirectionSelectForPin(uint8_t GroupName ,uint8_t PinNo ,uint8_t DirectionState );

/**
 * @fn      DIO_DirectionSelectForGroup
 * @brief 
 * @author Hisham Ahmed (Hisham.ah.hamed@gmail.com)
 * @date 2026-10-06
 * @version 0.1
 * @copyright Copyright (c) 2026 Gestell. All rights reserved.
 * @param[in] GroupName 
 * @param[in] DirectionState 
 */
void DIO_DirectionSelectForGroup(uint8_t GroupName ,uint8_t DirectionState );

/**
 * @fn 
 * @brief 
 * @author Hisham Ahmed (Hisham.ah.hamed@gmail.com)
 * @date 2026-10-06
 * @version 0.1
 * @copyright Copyright (c) 2026 Gestell. All rights reserved.
 * @param[in] GroupName 
 * @param[in] PinNo 
 * @param[in] OutputValue 
 */
void DIO_WriteForPin(uint8_t GroupName ,uint8_t PinNo ,uint8_t OutputValue );
/**
 * @fn 
 * @brief 
 * @author Hisham Ahmed (Hisham.ah.hamed@gmail.com)
 * @date 2026-10-06
 * @version 0.1
 * @copyright Copyright (c) 2026 Gestell. All rights reserved.
 * @param[in] GroupName 
 * @param[in] OutputValue 
 */
void DIO_WriteForGroup(uint8_t GroupName ,uint8_t OutputValue );

/**
 * @fn 
 * @brief 
 * @author Hisham Ahmed (Hisham.ah.hamed@gmail.com)
 * @date 2026-10-06
 * @version 0.1
 * @copyright Copyright (c) 2026 Gestell. All rights reserved.
 * @param[in] GroupName 
 * @param[in] PinNo 
 * @param[in] InputState 
 */
void DIO_ReadInputForPin(uint8_t GroupName ,uint8_t PinNo ,uint8_t *InputState );
/**
 * @brief 
 * @author Hisham Ahmed (Hisham.ah.hamed@gmail.com)
 * @date 2026-10-06
 * @version 0.1
 * @copyright Copyright (c) 2026 Gestell. All rights reserved.
 * @param[in] GroupName 
 * @param[in] InputState 
 */
void DIO_ReadInputForGroup(uint8_t GroupName ,uint8_t *InputState);
/**
 * @brief 
 * @author Hisham Ahmed (Hisham.ah.hamed@gmail.com)
 * @date 2026-10-06
 * @version 0.1
 * @copyright Copyright (c) 2026 Gestell. All rights reserved.
 * @param[in] GroupName 
 * @param[in] PinNo 
 */

void DIO_ToggleForPin(uint8_t GroupName ,uint8_t PinNo );
/**
 * @brief 
 * @author Hisham Ahmed (Hisham.ah.hamed@gmail.com)
 * @date 2026-10-06
 * @version 0.1
 * @copyright Copyright (c) 2026 Gestell. All rights reserved.
 * @param[in] GroupName 
 */
void DIO_ToggleForGroup(uint8_t GroupName  );
/**
 * @brief 
 * @author Hisham Ahmed (Hisham.ah.hamed@gmail.com)
 * @date 2026-10-06
 * @version 0.1
 * @copyright Copyright (c) 2026 Gestell. All rights reserved.
 * @param[in] GroupName 
 * @param[in] PinNo 
 * @param[in] PullUpState 
 */
void DIO_InternalPullUpControl(uint8_t GroupName ,uint8_t PinNo,uint8_t PullUpState);


 #endif 