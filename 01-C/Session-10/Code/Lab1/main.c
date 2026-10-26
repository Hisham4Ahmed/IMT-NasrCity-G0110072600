// Write a C code that apply the bubble sorting algorithm on a set of
// numbers entered by the user. The code shall ask the user to enter the
// number of values to be sorted, then the code shall ask the user to enter
// the values then print them in ascending order.


// 1- apply the bubble sorting   ascending order 
// 2- Enter the Size and Numbers  

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    uint8_t NumberSize = 0 ; 
    uint8_t *Numbers   = NULL;
    uint8_t Count    = 0 ;
    uint8_t Inner    = 0 ;
    uint8_t Outter   = 0 ;
    uint8_t State    = 0 ;
    uint8_t EnterState = 0 ;
    do{
    system("clear");
    printf("Enter A  to Start new Number and B to Append to last Array:");
    scanf(" %c",&EnterState);
    if(EnterState=='A')
    {
         /*Scan Size */
    printf("Enter the Size of Number:");
    scanf("%hhd",&NumberSize);
    /*Allocate*/
    Numbers = (uint8_t *)malloc(NumberSize);
    /*Check Numbers */
    if(Numbers!=NULL)
    {
        /*Scann the Numbers */
        for (Count=0; Count<NumberSize;Count++)
        {
            printf("Enter the Number[%d]:",Count+1);
            scanf("%hhd",&Numbers[Count]);
        }
        /*Bubble Sort*/
        for(Outter=0;Outter<NumberSize-1;Outter++)
        {
            for(Inner=0;Inner<NumberSize-1-Outter;Inner++)
            {
                if(Numbers[Inner]>Numbers[Inner+1])
                {
                    uint8_t temp = Numbers[Inner];
                    Numbers[Inner]=Numbers[Inner+1];
                    Numbers[Inner+1]=temp;
                }
            }
        }
        /*Display*/
        for(Count=0;Count<NumberSize;Count++)
        {
            printf("Number[%d]=%d\n",Count+1,Numbers[Count]);
        }
    }
    }
    else if (EnterState=='B')
    {
        printf("Enter the Total Number:");
        scanf("%hhd",&NumberSize);
        realloc(Numbers,NumberSize);
        for (Count=0; Count<NumberSize;Count++)
        {
            printf("Enter the Number[%d]:",Count+1);
            scanf("%hhd",&Numbers[Count]);
        }
                /*Bubble Sort*/
        for(Outter=0;Outter<NumberSize-1;Outter++)
        {
            for(Inner=0;Inner<NumberSize-1-Outter;Inner++)
            {
                if(Numbers[Inner]>Numbers[Inner+1])
                {
                    uint8_t temp = Numbers[Inner];
                    Numbers[Inner]=Numbers[Inner+1];
                    Numbers[Inner+1]=temp;
                }
            }
        }
        /*Display*/
        for(Count=0;Count<NumberSize;Count++)
        {
            printf("Number[%d]=%d\n",Count+1,Numbers[Count]);
        }
    }
    printf("Enter E to Exist:");
    scanf(" %c",&State);

}while(State!='E');

    return  0 ;
}