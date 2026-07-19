#include<stdio.h>
#include"STD_TYPES.h"

typedef struct
{
    u8 maths ;
    u8 language;
    u8 physics ;
    u8 chemistry ;
}students;

int main()
{
    u8 id;
    students arr[10] =
    {
        {10,20,30,40},
        {10,20,30,40},
        {10,20,30,40},
        {10,20,30,40},
        {10,20,66,40},
        {10,20,30,40},
        {10,20,30,40},
        {10,20,30,40},
        {10,20,30,40},
        {10,20,30,40}
    };

    printf("Enter the student ID : ");
    scanf("%hhd",&id);
    (id<1 || id>10)? printf("Invalid ID\n"):printf("Math grade is %d\nlanguage grade is %d\nphysics grade is %d\nchemistry grade is %d\n",arr[id-1].maths,arr[id-1].language,arr[id-1].physics,arr[id-1].chemistry);
}
