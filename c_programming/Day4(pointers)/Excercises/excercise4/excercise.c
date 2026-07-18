#include<stdio.h>

int main()
{
    int arr[10],sum=0;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        printf("please enter value %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    printf("the sum of the array is :%d\n",sum);
    

}