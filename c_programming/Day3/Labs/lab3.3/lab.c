#include<stdio.h>
int num ;
//void pall(int);
int get_length(int);

int main()
{
    int res ;
    scanf("%d",&num);
    res = get_length(num);
    printf("%d",res);
    

}
/*void pall(int num)
{
    
}
*/
/*char even_or_off(int num)
{
    int length = get_len();
}*/

int get_length(int num )
{   int len = 0;
    if (num == 0 ) return len ;
    else if (num < 0) num = -num ;
    for (num ; num > 0 ; num/10)
    {

        len++ ;
    }
    return len ;

}

