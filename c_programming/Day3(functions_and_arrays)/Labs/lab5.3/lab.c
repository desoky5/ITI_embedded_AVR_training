#include<stdio.h>
void swap(int*,int*);
int main()
{
    int arr[5]={4,3,5,2,1} ,sum=0 ;
    
    for(int i = 0 ;i<4;i++)
    {
        for(int j = 0 ;j<4-i;j++)
        if (arr[j]>arr[j+1])
        {
           swap(&arr[j],&arr[j+1]);
        }
        
    }
    for(int i = 0 ;i<5;i++)
    {
        printf(" %d\n",arr[i]);
    }
 

}
void swap (int* num1,int* num2)
 {
    int temp;
    int * ptr = &temp; 
    *ptr = *num2;
    *num2=*num1;
    *num1=*ptr;
}