#include<stdio.h>

int main()
{
    int first_operand , second_operand,operation,result;
    printf("Enter the first operand : ");
    scanf("%d",&first_operand);
    printf("Enter the second operand : ");
    scanf("%d",&second_operand);
    printf("Enter the desired operation : ");
    scanf("%d",&operation);
    switch (operation)
    {
    case 1:
        result=first_operand + second_operand ;
        printf("result = %d + %d = %d\n",first_operand,second_operand,result);
        break;
    case 2:
        result=first_operand - second_operand ;
        printf("result = %d - %d = %d\n",first_operand,second_operand,result);
        break;
    case 3:
        result=first_operand * second_operand ;
        printf("result = %d * %d = %d\n",first_operand,second_operand,result);
        break;
    case 4:
        result=first_operand / second_operand ;
        printf("result = %d / %d = %d\n",first_operand,second_operand,result);
        break;
    
    }

}
