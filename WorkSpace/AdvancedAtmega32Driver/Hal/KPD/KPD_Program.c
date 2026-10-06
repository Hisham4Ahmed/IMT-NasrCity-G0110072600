/**
 * 
 */

#include "KPD_Interface.h"
#include <util/delay.h>
void KPD_Init()
{
    uint8_t KPD_RowGroups[KPD_RowNo] = KPD_RowGroupsConfigured;
    uint8_t KPD_RowPins[KPD_RowNo] = KPD_RowPinsConfigured;
    uint8_t KPD_ColGroups[KPD_ColNo] = KPD_ColGroupsConfigured;
    uint8_t KPD_ColPins[KPD_ColNo] = KPD_ColPinsConfigured;

    // Row as Input 
    // Row as Internal Pull Up 
    for(uint8_t RowIndex = 0;RowIndex<KPD_RowNo;RowIndex++)
    {
        DIO_DirectionSelectForPin(KPD_RowGroups[RowIndex],KPD_RowPins[RowIndex],DIO_Input);
        DIO_InternalPullUpControl(KPD_RowGroups[RowIndex],KPD_RowPins[RowIndex],Enable);
    }
    // Coloum as Output
    // Coloum Init value as High  
    for(uint8_t ColIndex = 0;ColIndex<KPD_ColNo;ColIndex++)
    {
        DIO_DirectionSelectForPin(KPD_ColGroups[ColIndex],KPD_ColPins[ColIndex],DIO_Output);
        DIO_WriteForPin(KPD_ColGroups[ColIndex],KPD_ColPins[ColIndex],DIO_High);
    }
}
void KPD_GetKPDValue(uint8_t *KPD_Value)
{
    if(KPD_Value==NULL)
    {
        return ;
    }
    uint8_t KPDValues[KPD_RowNo][KPD_ColNo]=KPDValueConfigured;
    uint8_t KPD_RowGroups[KPD_RowNo] = KPD_RowGroupsConfigured;
    uint8_t KPD_RowPins[KPD_RowNo] = KPD_RowPinsConfigured;
    uint8_t KPD_ColGroups[KPD_ColNo] = KPD_ColGroupsConfigured;
    uint8_t KPD_ColPins[KPD_ColNo] = KPD_ColPinsConfigured;

    *KPD_Value=0xFF;
    uint8_t IsBtnPressed = 1;
    for(uint8_t C = 0 ;C<KPD_ColNo;C++)
    {
        DIO_WriteForPin(KPD_ColGroups[C],KPD_ColPins[C],DIO_Low);
        for(uint8_t R=0;R<KPD_RowNo;R++)
        {
            DIO_ReadInputForPin(KPD_RowGroups[R],KPD_RowPins[R],&IsBtnPressed);
            if(IsBtnPressed==0)
            {
                _delay_ms(100);
                DIO_ReadInputForPin(KPD_RowGroups[R],KPD_RowPins[R],&IsBtnPressed);
                if(IsBtnPressed==0)
                {
                    *KPD_Value=KPDValues[R][C];
                    DIO_WriteForPin(KPD_ColGroups[C],KPD_ColPins[C],DIO_High);
                    return ;
                }

            }
        }
        DIO_WriteForPin(KPD_ColGroups[C],KPD_ColPins[C],DIO_High);
    }
}











