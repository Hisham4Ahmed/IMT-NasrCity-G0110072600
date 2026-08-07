#include <stdio.h>
#include "Config.h"
#include "Bitmath.h"

int main()
{
    #if Version==MiddleEast
        printf("MaxSpeed=100\n");         
        printf("MaxTemp=20\n"); 
        printf("Airbag=2\n");
    #elif Version==Europ
        printf("MaxSpeed=200\n");         
        printf("MaxTemp=18\n"); 
        printf("Airbag=3\n");
    // #else 
    //     #warning "Invaild VersionConfig404"
    //     printf("MaxSpeed=200\n");         
    //     printf("MaxTemp=18\n"); 
    //     printf("Airbag=3\n");
    #else 
        #error "Invaild VersionConfig404"



        

    #endif
}