#include<stdio.h>
#include<string.h>

typedef struct
{
    char username[50];
    char pass[20];
    
}user;

int main()
{
    int j = 0;
    int found = 0;
    char username[50] , password[20];
    user users[]=
    {
        {"admin","1234"},
        {"guest","2408"}
    };

    int size = sizeof(users)/sizeof(users[0]);

    user activeusers[20];
    

    printf("Enter your user name : ");
    scanf("%s",username);
    printf("Enter your password : ");
    scanf("%s",password);

    for(int i = 0 ; i <size;i++)
    {
        int n1 = strcmp(users[i].username,username);
        int n2 = strcmp(users[i].pass,password);
        if (n1 == 0 && n2==0)
        {
            found = 1;
            strcpy(activeusers[j].username,users[i].username);
            strcpy(activeusers[j].pass,users[i].pass);
            printf("Successful login for user %s\n",activeusers[j].username);
            j++;
            break;
        }
    }
    if (!found)
    {
        printf("Login error \n");
    }
    else {
        printf("Active users :\n");
        for (int i = 0;i<j;i++)
        {
            printf("%s\n",activeusers[i].username);
        }
    }

}
