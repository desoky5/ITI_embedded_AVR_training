#include<stdio.h>
float power_fun(float,float);
int main()
{
    float base ;
    float power ;
    printf("Enter your base number : ");
    scanf("%f",&base);
    printf("Enter your power number : ");
    scanf("%f",&power);
    power_fun(base, power);


    
}
float power_fun (float base , float power )
{
    float res = 1;
    for (power ; power >0 ; power --)
    {
        res = base * res;
     
    }
    printf("Answer is : %.2f \n",res);
}