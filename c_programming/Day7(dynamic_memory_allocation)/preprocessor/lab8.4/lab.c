#include<stdio.h>

#define x 7
#define y 10
#define square(x) x*x 
#define func(x,y) ((x+y)*(x+y))

int main()
{
    printf("X is : %d\n",x);
    printf("X^2 is : %d\n",square(x));
    printf("value is : %d\n",func(x,y));
}