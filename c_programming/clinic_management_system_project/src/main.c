#include<stdio.h>
#include<string.h>
#include"../inc/STD_TYPES.h"
#define MAX_TRIALS 3

typedef struct
{


}reservations;

int main()
{
    u8 mode,auth_flag=0, password[20];
    printf("-------------------- ----Welcome to our clinic--------------------------\n");
    printf("Sellect your mode for admin mode press ( 0 ) and for user mode press  ( 1 )\n");
    scanf("%hhd",&mode);
    switch (mode)
    {
    case 0:
        printf("------------------------Welcome to Admin mode-------------------------\n");
        while (auth_flag<MAX_TRIALS)
        {
            printf("Enter admin password for Admin mode Authentication( %d trial%s left ):",(MAX_TRIALS-auth_flag),(MAX_TRIALS-auth_flag==1)?"":"s");
            scanf("%s",password);
            if (strcmp(password,"1234")==0)
            {
                printf("---------------------Authenticated successfully-----------------------\n");
                break;//to stop asking the user in admin mode  to enter the password again (terminates the while lopp)
            }
            auth_flag++;//increment the flag for every incorrect trial
        }
        if(auth_flag>=MAX_TRIALS) printf("----------------------------Authention Error--------------------------\n");
        break;
    
    case 1:
        printf("------------------------Welcome to user mode--------------------------\n");
        break;
    }

    return 0 ;
}