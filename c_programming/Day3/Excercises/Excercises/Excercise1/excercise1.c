#include<stdio.h>
//FUNCTION DECLARATION
int factorial(int);

int main()
{   //FUNCTION CALLING
    int num ;
    printf("Enter a number :\n");
    scanf("%d",&num);
    factorial(num);
    return 0 ;
}
//FUNCTION IMPLEMENTATION
int factorial(int num) //If the function will not return a value , best practice in c is to put void in the praces rather than c++ it does not matter ']]]]]]]]]]]]]]]]]]]]]]]]]]
{
    int res = 1 ;
    for (num;num>0;num--)
    {
        res=res*num;
    }
    printf("the factorial of is : %d \n",res);

}