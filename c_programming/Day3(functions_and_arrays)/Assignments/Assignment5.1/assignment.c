#include<stdio.h>
void swap(int*,int*);
int main()
{
    int arr[7];
    int n = sizeof(arr)/sizeof(arr[0]);//size of gives the whole size of the array in the memory so we need to divide by the size of each element that differs based on the data type of elements stored in the array to get the number of elements stored 
    for(int i = 0 ;i<n;i++)
    {
        printf("Enter element number %d:",i+1);
        scanf("%d",&arr[i]);
        
    }
    
    for(int i = 0 ;i<n-1;i++)
    {
        for(int j = 0 ;j<n-1-i;j++)
        if (arr[j]>arr[j+1])
        {
           swap(&arr[j],&arr[j+1]);
        }
        
    }
    printf("Maximum number in array = %d\n",arr[n-1]);
    printf("Minimum number in array = %d\n",arr[0]);

 

}
void swap (int* num1,int* num2)
 {
    int temp;
    int * ptr = &temp; 
    *ptr = *num2;
    *num2=*num1;
    *num1=*ptr;
}