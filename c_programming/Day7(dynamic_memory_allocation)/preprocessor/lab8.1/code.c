#include<stdio.h>

int main()
{
    printf("Hello\n");
    return 0 ;
}
//Extract the indermediate file from the toolchain 
//command << gcc -E main.c -o code.i >>(your working directory is the directory of the compiled folder)
//this is the result of the preprocessor to only replace each #include with the content of the included file 

//----------------------------------------------------------------------------
//Get the assembly file from compiler 
//command<<gcc -S code.c -o code.asm>>

//----------------------------------------------------------------------------
//Get the object file from compiler 
//command<<gcc -c code.c -o code.o>>