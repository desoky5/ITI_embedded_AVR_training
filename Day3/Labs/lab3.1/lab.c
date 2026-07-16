#include<stdio.h>

int main()
{
    int size ,i;
    printf("Enter array size for initialization : ");
    scanf("%d",&size);
    int arr[size];

    for (i=0; i < size ;i++)
    {
        printf("enter number of index %d : ",i);
        scanf("%d",&arr[i]);
       
    }
    
     for (i=0; i < size ;i++)
    {
        printf("index %d has a number : %d\n",i ,arr[i]);
    }
    printf("--------Reversed print------ \n");
    
    for (i=size-1 ; i >= 0 ;i--)
    {
    printf("index %d has a number : %d\n",i ,arr[i]);
         }
    

    
         
    

}
    
