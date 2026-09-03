#include "SevSeg_Interface.h"

static uint8_t SSDAnodeNumber[SSDMaxNumber] = 
{
    Anode_Zero  , 
    Anode_One   , 
    Anode_Two   , 
    Anode_Three , 
    Anode_Four  , 
    Anode_Five  , 
    Anode_Six   , 
    Anode_Seven , 
    Anode_Eight , 
    Anode_Nine  , 
};


void SSD_Init(uint8_t SSD_ID)
{
    if(SSD_ID==SSD1)
    {
        DIO_DirectionSelectForGroup(SSD1Group,DIO_AllOutput);
    }
    else if (SSD_ID==SSD2)
    {
        DIO_DirectionSelectForGroup(SSD2Group,DIO_AllOutput);
    }
    else
    {

    }
}

void SSD_DisplayNo(uint8_t SSD_ID , uint8_t Number)
{
    if(Number<SSDMaxNumber)
    {
        if(SSD_ID==SSD1)
        {
            DIO_WriteForGroup(SSD1Group,SSDAnodeNumber[Number]);
        }
        else if(SSD_ID==SSD2)
        {
            DIO_WriteForGroup(SSD2Group,SSDAnodeNumber[Number]);
        }   
    }

}
