//Calculate the factorial of an integer entered by the user using while loop
#include<stdio.h>

int main()
{
    int num=0,result=1;
    printf("Enter an integer : ");
    scanf("%d",&num);
    while(num>0)
    {
        result = num*result;
        num -- ;
    }
    printf("Factorial is:%d\n",result);

}