#include<stdio.h>
int check_even(int);
int check_odd(int);

int main()
{
    int arr[10], even_sum =0 ,odd_sum = 0;
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0 ; i < n ; i++)
    {
        printf("Enter Element number %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    for (int i = 0;i<n;i++)
    {
        if (arr[i]%2==0) even_sum +=arr[i];
        else if (arr[i]%2 != 0) odd_sum +=arr[i];
    }
    printf("Sum of even numbers is : %d\n",even_sum);
    printf("Sum of odd numbers is : %d\n",odd_sum);
}
