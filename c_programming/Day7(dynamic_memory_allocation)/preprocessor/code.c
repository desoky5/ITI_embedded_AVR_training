#include<stdio.h>

int main()
{
    printf("Hello\n");
    return 0 ;
}
//STEP1: Extract the indermediate file from the toolchain 
//command << gcc -E main.c -o code.i >>(your working directory is the directory of the compiled folder)
//this is the result of the preprocessor to only replace each #include with the content of the included file 

//----------------------------------------------------------------------------
//STEP2: Get the assembly file from compiler 
//command<<gcc -S code.c -o code.asm>>

//----------------------------------------------------------------------------
//STEP3: Get the object file from compiler 
//command<<gcc -c code.c -o code.o>>
//to preview the content of the object file on terminal << objdump -d code.o   >>

//----------------------------------------------------------------------------
//STEP4: Get the executable file from compiler 
//command<<gcc code.c -o code >>

