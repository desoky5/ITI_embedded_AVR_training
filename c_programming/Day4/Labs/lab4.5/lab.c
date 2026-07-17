//Recive values of array of fixed size and print the summation of these values (using pointers)
#include<stdio.h>
void func(int* ptr)
{
   int sum = 0 ;

    for (int i = 0 ; i<10;  i++)
    {   
        sum += *(ptr+i);
        
    }
    printf("sum is : %d\n",sum);
}

int main()
{
    int arr[10];
    for(int i = 0 ;i < 10 ;i++)
    {
        printf("Enter values %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    //arr == @arr[0]
    func(arr);
    return 0;
    
}
