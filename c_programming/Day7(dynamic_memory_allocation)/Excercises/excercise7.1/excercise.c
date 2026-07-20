#include<stdio.h>
#include<stdlib.h>

int main()
{
    char* ptr = malloc(10*sizeof(char));//casting the void pointer to character pointer 
    if (ptr != NULL)
    {
        printf("Allocated succ\n");
    }
    else 
    {
        printf("Failed to allocated\n");
    }
    free(ptr);
    int* ptr1 = (int*)calloc(10,sizeof(int));//casting generic pointer to int pointer 
       if (ptr != NULL)
    {
        printf("Allocated succ\n");
    }
    else 
    {
        printf("Failed to allocated\n");
    }
    free(ptr1);

}