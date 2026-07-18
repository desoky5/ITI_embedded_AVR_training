//Binary Search
#include<stdio.h>
int binary_search(int*,int,int);
int main()
{
    int arr[10],target;
    int n = sizeof(arr)/sizeof(arr[0]);//size of gives the whole size of the array in the memory so we need to divide by the size of each element that differs based on the data type of elements stored in the array to get the number of elements stored 
    for(int i = 0 ;i<n;i++)
    {
        printf("Enter element number %d:",i+1);
        scanf("%d",&arr[i]);   
    }
    printf("Enter search target number:");
    scanf("%d",&target);
    int res = binary_search(arr,target,n);
    (res==-1)?printf("Target not found"):printf("Target found at index %d\n",res);
}

int binary_search(int arr[] , int target,int n)
{
    int start = 0 , end =n-1,mid;
    while(start<=end)
    {
        mid=start+((end-start)/2);
        if(arr[mid]==target) 
        {
            return mid ;
        }
        else if (arr[mid]>target)
        {
            end=mid-1;
        }
        else if(arr[mid]<target)
        {
            start=mid+1;
        }
    }
    return -1 ; 
}