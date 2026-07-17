/*Write C Code that simulate an alarm system that ask the
user to enter the result of certain mathematical example ,
the system must keep asking the user to enter the result
till reach the correct result*/
#include<stdio.h>

int main()
{
  
    while(1)
    {
        int num ; 
        printf("Enter the result of 2+3 : ");
        scanf("%d",&num);

        if (num == 5 )
        {
            printf("correct\n");
            break;
        }
    printf("Try Again\n");
    }
    return 0 ;

}
