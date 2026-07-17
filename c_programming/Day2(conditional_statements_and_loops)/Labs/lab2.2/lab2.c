#include<stdio.h>

int main()
{
    char x , y , z ;
    printf("Enter three values  to get the max: ");
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);
    (x>y)?((x>z)? printf("Max number is %d \n",x) : printf("Max number is %d \n",z)): ((y>z)? printf("Max number is %d \n",y) : printf("Max number is %d \n",z)); // semicolon to be put at the end of the line not with each ternary operator
}