//Linear Search Algorithm
#include<stdio.h>

int main()
{
    int arr[10],target,count=0;
    int n = sizeof(arr)/sizeof(arr[0]);//size of gives the whole size of the array in the memory so we need to divide by the size of each element that differs based on the data type of elements stored in the array to get the number of elements stored 
    for(int i = 0 ;i<n;i++)
    {
        printf("Enter element number %d:",i+1);
        scanf("%d",&arr[i]);   
    }
    printf("Enter target number:");
    scanf("%d",&target);
    
    for(int i = 0 ;i<n;i++)
    {
        if(target==arr[i]) count++ ;
        
    }
   
    if(count>0) printf("Value Exists %d times\n",count);
    else printf("Value does not exist\n");

}
