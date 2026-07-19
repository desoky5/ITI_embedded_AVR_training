#include<stdio.h>
#include"STD_TYPES.h"

typedef struct {
    u16 x ;
    u16 z ;
    u32 y ;
    u32 k ;
}mystruct;

int main()
{
    printf("Size of struct is : %ld",sizeof(mystruct));
}