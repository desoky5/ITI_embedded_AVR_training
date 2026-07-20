#include<stdio.h>
#include<stdlib.h>
int main()
{
    int size ,temp;
    int *ptr;
    printf("Enter number of values to be stored:");
    scanf("%d",&size);//recieve the size of the size of the dynamically allocated memory from user 
    ptr = (int*)malloc(size* sizeof(int));

    if(ptr== NULL)//check that the memory has been already allocated 
    {
        printf("Allocation Failed");
        return 1 ;
    }

    for(int i = 0;i<size;i++)
    {
        printf("Enter element number %d:",i+1);
        scanf("%d",ptr+i);
    }
    
    for (int i = 0;i<size-1;i++)
    {
        for (int j = 0; j< size-i-1; j++)
        {
            if(ptr[j] > ptr[j+1])
            {
                temp = ptr[j];
                ptr[j]=ptr[j+1];
                ptr[j+1]=temp;

            }
        }
    }
    printf("Sorted Array: \n");
    for(int i = 0;i<size;i++)
    {
        printf("Element no  %d = %d\n",i+1,*(ptr+i));
    }
    free(ptr);
    return 0;

}
