#ifndef LCD_PRIVATE
#define LCD_PRIVATE

#define Lcd_8BitMode   1
#define Lcd_4BitMode   2


// 00001DCB
// 00001000
// 00001DCB
// 00001110 
#define Lcd_DisplayOff 0x08
#define Lcd_DisplayOn  0x0C
#define Lcd_CursorOn   0x0E
#define Lcd_CursorBlinkingOn 0x0F




#define Lcd_Line1      0 
#define Lcd_Line2      1
#define Lcd_Line1Address 0x00
#define Lcd_Line2Address 0x40 

#endif /* LCD_PRIVATE */
