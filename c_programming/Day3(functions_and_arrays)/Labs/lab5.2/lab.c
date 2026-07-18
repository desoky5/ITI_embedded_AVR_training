#include<stdio.h>

int main()
{
    int arr[10],sum=0;
    for(int i = 0 ;i<10;i++)
    {
        printf("Please enter number %d:",i+1);
        scanf("%d",&arr[i]);
    }
    for(int i = 0 ;i<10;i++)
    {
        sum +=arr[i];
    }
    printf("The sum of the array elements = %d\n",sum);

}