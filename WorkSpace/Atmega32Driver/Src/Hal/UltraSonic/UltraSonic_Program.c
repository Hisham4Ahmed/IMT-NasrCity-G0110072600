



static void UltraSonic_EdgeProcessing()
{
    // 1- at Pos 1 will reset timer and change to falling 

    // 2- at pos 2 will read the ICR1 Value And this value map to Travel Time and change to Rising 
    // 3- after finish reset flag 
}



void Ultrasonic_Init()
{
    // 1- Config to DIO Direction 
    // 2- Init to the ICU Driver -> call the Call Back function(UltraSonic_EdgeProcessing) & Call the ICU_Init 
}

void UltraSonic_Trigger()
{
    // 0-  Check on flag 
    // 1- Send the 10usec high puls on Specific DIO pin and After that Make it Low 
    // Note : Make Sure from UltraSonic Flag 
}
uint8_t UltraSonic_GetDistance(uint16_t *DistanceValue)
{
    // make sure the Porcessing Finished 
    // calc the Distance 
}





