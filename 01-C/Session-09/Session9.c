#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "BitMath.h"

#define ArrSize    10
#undef  ArrSize 
#define ArrSize    100 
int main()
{
    uint8_t size = 10 ;
    // uint8_t arr[size] ;
    uint16_t arr2[ArrSize] = {0};
    long int arr3[ArrSize] = {0};
    // // uint16_t arr2[ArrSize] = {0};
    // uint8_t count = 0 ;
    // for(count = 0; count<ArrSize;count++)
    // {
    //     scanf("%hhd",&arr[count]);
    //     scanf("%hd",&arr2[count]);
    //     scanf("%ld",&arr3[count]);

    //     printf("%d\n",count);
    // }
    // uint8_t Reg =0xf0;
    // SetBit(Reg,0);// 0xf1;
    // printf("0x%X\n",Reg);

    HelloMessage();
    return   0; 
}
