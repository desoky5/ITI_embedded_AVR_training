#include<stdio.h>
#define x 7

int main()
{
   
    int y = 0 ;
    #if x==7 //the variable must be set by a preprocessor directive like #define above 
     y=1;
     #warning "Condition met"
    #elif x==5
     y=2;
     #error "Error raised"
    #endif

    printf("Y is : %d",y);

}