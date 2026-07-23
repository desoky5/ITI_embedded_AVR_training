#include<stdio.h>
#include"../inc/STD_TYPES.h"
int main()
{
    char mode;
    printf("----------------------------Welcome to our clinic--------------------------\n");
    printf("Sellect your mode for admin mode press ( 0 ) and for user mode press  ( 1 )\n");
    scanf("%hhd",&mode);
    switch (mode)
    {
    case 0:
        printf("------------------------Welcome to Admin mode-------------------------\n");
        break;
    
    case 1:
        printf("------------------------Welcome to user mode--------------------------\n");
        break;
    }

    return 0 ;
}