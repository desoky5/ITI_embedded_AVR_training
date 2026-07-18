#include<stdio.h>
void swap (int , int );

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
        if (arr[i]>arr[i+1])
        {
            swap(arr[i],arr[i+1]);
        }
        
    }
    

}
void swap (int num1 , int num2)
{
    int temp , 
    temp = num1;
    num1=num2;
    num2=temp;
}