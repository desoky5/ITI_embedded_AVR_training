#include<stdio.h>

void max_fun(int num1,int num2,int* max)
{
    if (num1>num2)
    {
        *max = num1;
    }
    else if (num2>num1)
    {
        *max = num2;
    }
}
int main()
{
    int num1,num2,max;
    printf("Enter first num : ");
    scanf("%d",&num1); 
    printf("Enter seconf num : ");
    scanf("%d",&num2);
    max_fun(num1,num2,&max);
    printf("Max value is : %d",max);

}