#include<stdio.h>
int main()
{
    while(1)
    {
        int num ;
        printf("Please enter a number : ");
        scanf("%d",&num);
        if(num>100)
        {
            printf("thanks \n");
            break;//if we replaces the if with a while , the program will behave in a different way as break breaks the nearest enclosing loop or switch 
        }
        
    }
}