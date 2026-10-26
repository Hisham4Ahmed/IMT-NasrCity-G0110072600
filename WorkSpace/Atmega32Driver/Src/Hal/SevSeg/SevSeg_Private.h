#ifndef SEVSEG_PRIVATE
#define SEVSEG_PRIVATE

#define SSDMaxNumber   10 
typedef enum 
{
    Anode_Zero =0xC0 ,/*0b11000000*/
    Anode_One  =0xF9 ,/*0b11111001*/
    Anode_Two  =0xA4 ,/*0b10100100*/
    Anode_Three=0xB0 ,/*0b10110000*/
    Anode_Four =0x99 ,/*0b10011001*/
    Anode_Five =0x92 ,/*0b10010010*/
    Anode_Six  =0x82 ,/*0b10000010*/
    Anode_Seven=0xF8 ,/*0b11111000*/
    Anode_Eight=0x80 ,/*0b10000000*/
    Anode_Nine =0x90 ,/*0b10010000*/
}SSD_AnodeNo_t;

#define SSD1    1
#define SSD2    2

#endif /* SEVSEG_PRIVATE */
