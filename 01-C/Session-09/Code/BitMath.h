#define SetBit(Reg,BitNo)      Reg|=(1<<BitNo)
#define ClrBit(Reg,BitNo)      Reg&=~(1<<BitNo)
#define TogBit(Reg,BitNo)      Reg^=(1<<BitNo)
#define GetBit(Reg,BitNo)      (Reg>>BitNo)&1

// Reg & (1<<bitno)   0 0 0 1 0 0 1 0 
//                    0 0 0 1 0 0 0 0 
//                 -------------------
//                    0 0 0 1 0 0 0 0 -> 


// #define Enable  1 
// #define Disable 0 

#define HelloMessage()     printf("IMT\n");\
                           printf("Welcome Guys\n");\
                           printf("AVR-Diploma\n");

typedef unsigned char   u8 ;