#include<stdio.h>

int fact_fun(int);
int main()
{
    int num ,r ; 
    printf("Enter n : ");
    scanf("%d",&num);
    printf("Enter r : ");
    scanf("%d",&r);
    int npr = fact_fun(num)/fact_fun((num-r));
    printf("%d p %d = %d\n",num,r,npr);

}

int fact_fun(int num)
{ 
    int res = 1;
    for(num;num>0;num--)
    {
        res = res * num ;
    }
    return res ;
}