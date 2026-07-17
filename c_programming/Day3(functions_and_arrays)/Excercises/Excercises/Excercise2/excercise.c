#include<stdio.h>

int sum = 0;//the variable must be initalized gobally to be accessed from different scopes , and defined with initial value zero , so not have a garbge value.
int main()
{
    for (int i = 0;i<10;i++)
    {
        int num ;
        printf("Enter number %d:",i+1);
        scanf("%d",&num);//scaning the user data from terminal and accessing the addess of the variable num and put the value in 
        sum += num ;
    }
    printf("The summation of the entered ten numbers is:%d\n",sum);
    return 0 ;
}