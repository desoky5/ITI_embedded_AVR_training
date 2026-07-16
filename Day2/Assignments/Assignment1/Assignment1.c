#include<stdio.h>

int main()
{
    int num1,num2,num3;
    printf("Enter the first number : ");
    scanf("%d",&num1);
    printf("Enter the second number : ");
    scanf("%d",&num2);
    printf("Enter the third number : ");
    scanf("%d",&num3);
    (num1>num2)? ((num1>num3)? printf("Num1 %d is Max : \n",num1):printf("Num3 %d is Max \n",num3)):((num2>num3)? printf("Num2 %d is Max \n",num2):printf("Num 3 %d is Max \n",num3));

}

