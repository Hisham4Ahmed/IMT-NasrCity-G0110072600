#ifndef LCD_CONFIG
#define LCD_CONFIG
#include "../../Mcal/DIO/DIO_Interface.h"


#define LCD_Mode  Lcd_8BitMode

#define RSPin     DIO_Pin0
#define RSGroup   DIO_GroupA

#define RWPin     DIO_Pin1
#define RWGroup   DIO_GroupA

#define EPin     DIO_Pin2
#define EGroup   DIO_GroupA

#if LCD_Mode==Lcd_8BitMode
    #define DataGroup DIO_GroupC
#elif LCD_Mode==Lcd_4BitMode
    #define D4Pin        DIO_Pin4
    #define D4Group      DIO_GroupC 
    #define D5Pin        DIO_Pin5
    #define D5Group      DIO_GroupC
    #define D6pin        DIO_Pin6
    #define D6Group      DIO_GroupC
    #define D7Pin        DIO_Pin7
    #define D7Group      DIO_GroupC
#else 
    #error "Invaild Lcd Mode"
#endif /*LCDMode*/    
// 0 0 1 DL N F 0 0 
// 0 0 1 1  1 0 0 0
#define Lcd_FunctionSet  0x38

#define Lcd_DisplayOnOff   Lcd_DisplayOn
#define Lcd_Clear 0x01 
// 000001 I/D SH
// 000001  1  0 
#define Lcd_EntryMode  0x06

#endif /* LCD_CONFIG */
