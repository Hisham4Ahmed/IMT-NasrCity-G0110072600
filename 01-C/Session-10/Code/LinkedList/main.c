#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef struct hamda 
{
    uint8_t Info ; 
    struct hamda * Next ; 
}Test_t;

Test_t *Start = NULL;

void main()
{
    uint8_t Input = 0 ;
    Test_t  * NewElement =NULL; 
    Test_t  * Temp =NULL; 
    do 
    {
        printf("what are you need:");
        scanf("%hhd",&Input);
        if(Input==0)
        {
            // Add New Element from End 
            NewElement = (Test_t*)malloc(sizeof(Test_t));
            printf("Enter the Info:");
            scanf("%d",NewElement->Info);
            if(Start==NULL)
            {
                NewElement->Next=NULL;
                Start=NewElement;
            }
            else 
            {
                Temp=Start;
                while(Temp->Next!=NULL)
                {
                    Temp=Temp->Next;
                }
                NewElement->Next=NULL;
                Temp->Next = NewElement;
            }
        }
        else if(Input==1)
        {
            if(Start!=NULL)
            {
                Temp=Start;
                while(Temp!=NULL)
                {
                    printf("ElementInfo:%d\n",Temp->Info);
                    Temp=Temp->Next;
                }
            }
        }
        else if(Input==2)
        {
            
        }
        else
        {
            printf("incorrect entry\n");
        }
    }while(Input!=2);
}