#include<stdio.h>

int main()
{
    int first_number , second_number ;
    printf("Please Enter number a : ");
    scanf("%d",&first_number);
    printf("please Enter number b : ");
    scanf("%d",&second_number);
    printf("a + b = %d \n",(first_number + second_number));
    printf("a - b = %d \n",(first_number - second_number));
    printf("a & b = %d \n",(first_number & second_number));
    printf("a | b = %d \n",(first_number | second_number));
    printf("a ^ b = %d \n",(first_number ^ second_number));
}