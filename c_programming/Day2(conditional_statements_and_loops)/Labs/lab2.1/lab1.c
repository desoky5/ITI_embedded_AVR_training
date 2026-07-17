#include<stdio.h>

int main()
{
    //*************BITWISE OPERATORS*************** */
    //variables declaration
    char x = 10 ;
    char set , clear , toggle , get ;
    //SET BIT 0
    set = ( x | (1<<0) );
    //CLEAR BIT 1
    clear = ( set & ~(1<<1) );
    //TOGGLE BIT 3
    toggle = (clear ^ (1<<3));
    //GET BIT 2
    get = ( 1 &(toggle>>2));
    printf("set is : %d \n",set);
    printf("clear is : %d \n",clear);
    printf("toggle is: %d \n",toggle);
    printf("get is: %d \n",get);

}