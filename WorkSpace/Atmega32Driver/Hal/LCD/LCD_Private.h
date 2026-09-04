/**
 * @file  LCD_Private.h
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief  
 * @version 0.1
 * @date 2026-09-03
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#ifndef LCD_PRIVATE
#define LCD_PRIVATE

#define Lcd_8BitMode   1
#define Lcd_4BitMode   2


#define Lcd_ClearScreen 0x01

/**
    DisplayOnOFF
    D=1, display on; D=0, display off
    C=1, cursor on; C=0, cursor off
    B=1, cursor blinking on; B=0, cursor blinking off
    0 0 0 0 1 D C B
    0 0 0 0 1 0 0 0 -> D =0 C =0  B =0 
    0 0 0 0 1 1 0 0 -> D =1 C =0  B =0
    0 0 0 0 1 1 1 0 -> D =1 C =1  B =0
    0 0 0 0 1 1 1 1 -> D =1 C =1  B =1

*/
#define Lcd_DisplayOff                0x08
#define Lcd_DisplayOnCursorOff        0x0C
#define Lcd_DisplayOnCursorOnBlinkOff 0x0E
#define Lcd_DisplayOnCursorOnBlinkOn  0x0F


/*Function Set Options
    DL=1, 8-bit interface; DL=0, 4-bit interface
    N=1, 2-line display; N=0, 1-line display
    F=1, 5x11 dots font; F=0, 5x8 dots font
    0 0 1 DL N F x x
    0 0 1 0  0 1 0 0
*/
#define Lcd_4Bit2Line5x8F  0x28 
#define Lcd_4Bit2Line5x11F 0x2C
#define Lcd_4Bit1Line5x8F  0x20
#define Lcd_4Bit1Line5x11F 0x24
#define Lcd_8Bit2Line5x8F  0x38   
#define Lcd_8Bit2Line5x11F 0x3C        
#define Lcd_8Bit1Line5x8F  0x30    
#define Lcd_8Bit1Line5x11F 0x34

/*Entry Mode Set Options
    I/D=1, Increment AC (Cursor moves right)
    I/D=0, Decrement AC (Cursor moves left)
    S=1, screen shifting on
    S=0, screen shifting off
    0 0 0 0 0 1 I/D S
    0 0 0 0 0 1 0   0 -> I/D=0 S=0
    0 0 0 0 0 1 1   0 -> I/D=1 S=0
*/
#define Lcd_EntryMode_DecNoShift  0x04
#define Lcd_EntryMode_DecShift    0x05
#define Lcd_EntryMode_IncNoShift  0x06
#define Lcd_EntryMode_IncShift    0x07


/* Cursor or Display Shift Options
    S/C=1, shift screen; S/C=0, shift cursor
    R/L=1, to right-side; R/L=0, to left side
    0 0 0 1 S/C R/L x x
*/
#define Lcd_ShiftCursorLeft       0x10
#define Lcd_ShiftCursorRight      0x14
#define Lcd_ShiftDisplayLeft      0x18
#define Lcd_ShiftDisplayRight     0x1C




#define Lcd_Line1      0 
#define Lcd_Line2      1

#define Lcd_Line1Address 0x00
#define Lcd_Line2Address 0x40 


#define Lcd_SetDDRAMCommand 0x80
#define Lcd_SetCGRAMCommand 0x40
#define Lcd_CGRAMMaxLocation  8
#define Lcd_CGRAMMaxSizeofLocation  8 
#endif /* LCD_PRIVATE */
