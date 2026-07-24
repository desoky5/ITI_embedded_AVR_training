#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"../inc/STD_TYPES.h"
#define MAX_TRIALS 3



typedef struct node_records
{
    u8 ID;
    u8 Age;
    u8 gender[20];
    u8 Name[50];
    struct node_records *next;  
}records;

typedef struct node_reservations
{
    u8 name;
    u8 slot;
    struct node_reservations *next;  
}Reservations;

void Add_patient_record(records *Head,u8 ID,u8 Age,u8 *gender,u8 Name[50]);
void show_record(records *Head);

int main()
{
    u8 mode,auth_flag=0, password[20],admin_features,user_features,ID,Age,gender[20],Name[50];
    records *Head = (records*)malloc(sizeof(records));
    Head->next=NULL;
    if(Head ==NULL) return 1;
    printf("-------------------------Welcome to our clinic--------------------------\n");
    printf("Sellect your mode , for admin mode press ( 0 ) and for user mode press  ( 1 )\n");
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
        if(auth_flag>=MAX_TRIALS) 
        {
            printf("----------------------------Authention Error--------------------------\n");
            break;
        }
        while(1)
        {
        printf("To sellect from the follwing features press its coressponding number:\n");
        printf("1:Add Patient Record\n2:Edit Record\n3:Show today`s Reservatios\n4:Add a new reservation\n5:Cancel Reservation\n");
        scanf("%hhd",&admin_features);
        switch (admin_features)
        {
        case 1:
            printf("-----------------Adding patient record---------------\n");
            printf("Please Enter User Id :");
            scanf("%hhd",&ID);
            printf("Please Enter User Age:");
            scanf("%hhd",&Age);
            printf("Please Enter User Gender:");
            scanf("%s",gender);
            printf("Please Enter User Name:");
            scanf("%s",Name);
            Add_patient_record(Head,ID,Age,gender,Name);
            show_record(Head);
            break;
        case 2:
            printf("Edit record\n");
            break;
        case 3:
            printf("show today`s reservations\n");
            break;
        case 4:
            printf("Add reservation\n");
            break;
        case 5:
            printf("cancel Reservation\n");
            break;
        }}
        break;

    
    case 1:
        printf("------------------------Welcome to user mode--------------------------\n");
        break;
    return 0 ;
}}

void Add_patient_record(records *Head,u8 ID,u8 Age,u8 gender[20],u8 Name[50])
{
    records *current = Head ;
    records *last = Head ;
    while (current!=NULL)
    {
        if(current->ID==ID) 
        {
            printf("\n***********Invalid user id**************\n");
            return;
        }
        last =current;
        current =current->next;
    }
    records *newnode =(records*)malloc(sizeof(records));
    last->next=newnode;
    if (newnode ==NULL) return ;
    newnode->ID = ID ;
    newnode->Age = Age;
    strcpy((char*)newnode->gender, (char*)gender);
    strcpy((char*)newnode->Name, (char*)Name);
    newnode->next=NULL;
}

void show_record(records *Head)
{
    records *current = Head->next;
    printf("-----------------Clinic Users Record------------\n");
    while (current!=NULL)
    {
        printf("User Id:%d\n",current->ID);
        printf("User Age:%d\n",current->Age);
        printf("User Gender:%s\n",current->gender);
        printf("User Name:%s\n",current->Name);
        printf("-------------------------\n");
        current=current->next;
    } 
}