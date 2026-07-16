#include<stdio.h>

void fun(int a , int b , int* sum , int* sub)
{
    *sum = a + b;
    *sub = a - b ;

}
int main()
{
    int num1 , num2 , sum , sub;
    printf("Enter the first number : ");
    scanf("%d",&num1);
    printf("Enter the second number : ");
    scanf("%d",&num2);
    fun(num1,num2,&sum,&sub);
    printf("sum is : %d\n", sum);
    printf("sub is : %d\n",sub);

}