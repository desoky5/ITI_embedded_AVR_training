#include<stdio.h>
void bubble_sorting(int*,int);
void swap(int*,int*);
int main()
{
    int arr[10];
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        printf("Enter element number %d :",i+1);
        scanf("%d",&arr[i]);
    }
    bubble_sorting(arr,n);
    for (int i = 0; i < n; i++)
    {
        printf("element %d :%d\n",i+1,arr[i]);
    }
}
void bubble_sorting(int* ptr,int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (ptr[j]>ptr[j+1]) swap(&ptr[j],&ptr[j+1]);
        }  
    }
}

void swap(int* num1,int* num2)
{
    int temp ;
    int* ptr =&temp;//we must have a fully defined and initialized pointer before using it to have correct behaviour and no program corruption happens
    *ptr =*num1;
    *num1=*num2;
    *num2=*ptr;
}