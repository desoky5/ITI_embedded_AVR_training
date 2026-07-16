// take a word from th user and take a letter and count and print how many times this letter has appeared in that word 
#include<stdio.h>

int main()
{
    char str ;
    printf("Enter a string : ");
    scanf("%c",&str);
    int n = sizeof(str);
    for (int i = 0;  i < n ; i ++)
    {
        printf("%d", str[i]);
    }
}