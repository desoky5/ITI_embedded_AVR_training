#include<stdio.h>

int fact_fun(int);
int main()
{
    int num ,r ; 
    printf("Enter n : ");
    scanf("%d",&num);
    printf("Enter r : ");
    scanf("%d",&r);
    int ncr = fact_fun(num)/(fact_fun(r)*((num-r)));
    printf("%d c %d = %d\n",num,r,ncr);

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