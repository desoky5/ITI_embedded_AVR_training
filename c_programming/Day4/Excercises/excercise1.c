#include<stdio.h>

int main()
{
    int arr[6]={10,7,5,12,100,55};
    int target = 66 ;
    for (int i=0;i<6;i++)
    {

        if (arr[i]==target)
        {
            printf("Target index is : %d",i);
            break;
        } 
        else 
        {
             if (arr[i]!=target)
        {
            continue;
        } 
        else 
        {
          printf("Target not in list ");  
        }
        }

    }
    
}