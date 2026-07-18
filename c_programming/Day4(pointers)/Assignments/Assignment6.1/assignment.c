#include<stdio.h>
int main()
{
    int x=10 , y=20 , z=30;
    int* p=&x;
    int* q=&y;
    int* r=&z;
    int* temp;
    printf("x =%d\n",x);
    printf("y =%d\n",y);
    printf("z =%d\n",z);
    printf("p =%p\n",p);
    printf("q =%p\n",q);
    printf("r =%p\n",r);
    printf("*p =%d\n",*p);
    printf("*q =%d\n",*q);
    printf("*r =%d\n",*r);
    printf("-------Swapping pointers---------\n");
    temp = r ;
    r=p;
    p=q;
    q=temp;
    printf("x =%d\n",x);
    printf("y =%d\n",y);
    printf("z =%d\n",z);
    printf("p =%p\n",p);
    printf("q =%p\n",q);
    printf("r =%p\n",r);
    printf("*p =%d\n",*p);
    printf("*q =%d\n",*q);
    printf("*r =%d\n",*r);
    
}