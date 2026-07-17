/*Write C Code that take number from user and get its
multiplication table .
Boundaries: the table start from the entered num * 1
And ends at num * num */
#include<stdio.h>
int main()
{   
    int num;
    printf("Enter a number : ");
    scanf("%d",&num);
    for (int i = 0;i < num;i++)
    {
        printf("Multiplication table item %d is :%d * %d = %d \n",i+1,num , i+1 ,num*(i+1));
    }
}