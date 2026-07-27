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
    u8 Name[50];
    u8 slot;
    u8 ID;
    struct node_reservations *next;  
}Reservations;

void Add_patient_record(records *Head,u8 ID,u8 Age,u8 gender[20],u8 Name[50]);
void show_record(records *Head);
void Add_new_reservation(Reservations *Head,u8 Name[50],u8 slot,u8 ID);
void show_reservations(Reservations *Head);
void remove_last_reservation(Reservations* head);
void search_patient_record_by_id(records * Head ,u8 ID);

int main()
{
    u8 mode,auth_flag=0, password[20],admin_features,user_features,ID,Age,gender[20],Name[50],slot,ID_rec;
    records *Head = (records*)malloc(sizeof(records));
    if(Head ==NULL) return 1;
    Reservations *Head_res = (Reservations*)malloc(sizeof(Reservations));
    if(Head_res ==NULL) return 1;
    Head->next=NULL;
    Head_res->next=NULL;
    while(1)
    {
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
        u8 admin_running = 1 ;
        while(admin_running)
        {
        printf("To sellect from the follwing features press its coressponding number:\n");
        printf("0:back\n1:Add Patient Record\n2:Edit Record\n3:Show today`s Reservatios\n4:Add a new reservation\n5:Cancel Reservation\n");
        scanf("%hhd",&admin_features);
        switch (admin_features)
        {
        case 0 :
            admin_running = 0;
            break;
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
            printf("------------Today`s Reservations----------");
            show_reservations(Head_res);
            break;
        case 4:
            printf("-------------Our Available slots-----------\nSlot 1 : from 2 to 2:30\nSlot 2 : from 2:30 to 3:00\nSlot 3 : from 3:00 to 3:30\nSlot 4 : from 3:30 to  4:00\nSlot 5 : from 4:30 to 5:00\n");
            printf("Enter your name:");
            scanf("%s",Name);
            printf("Enter Slot No:");
            scanf("%hhd",&slot);
            printf("Enter Your ID:");
            scanf("%hhd",&ID);
            Add_new_reservation(Head_res,Name,slot,ID);
            break;
        case 5:
            printf("-----Deleting the Last Reservation-----\n");
            remove_last_reservation(Head_res);
            break;
        }}
        break;

    
    case 1:
        printf("------------------------Welcome to user mode--------------------------\n");
        u8 user_running = 1;
        while(user_running)
        {
        printf("To sellect from the follwing features press its coressponding number:\n");
        printf("0:back\n1:View today`s reservations\n2:Add Reservation\n3:cancel reservation\n4:Search for patient with ID\n");
        scanf("%hhd",&user_features);
        switch (user_features)
        {
        case 0 :
            user_running=0;
            break ;
        case 1:
            show_reservations(Head_res);
            break;
        
        case 2:
            printf("-------------Our Available slots-----------\nSlot 1 : from 2 to 2:30\nSlot 2 : from 2:30 to 3:00\nSlot 3 : from 3:00 to 3:30\nSlot 4 : from 3:30 to  4:00\nSlot 5 : from 4:30 to 5:00\n");
            printf("Enter your name:");
            scanf("%s",Name);
            printf("Enter Slot No:");
            scanf("%hhd",&slot);
            Add_new_reservation(Head_res,Name,slot,ID);
            show_reservations(Head_res);
            break;
        case 3:
            printf("-----Deleting your last Reservation-------\n");
            remove_last_reservation(Head_res);
        case 4 : 
            printf("Enter your ID:");
            scanf("%hhd",&ID_rec);
            search_patient_record_by_id(Head,ID_rec);
        }
        }
        break;
    }}
    return 0 ;
}

void Add_patient_record(records *Head,u8 ID,u8 Age,u8 gender[20],u8 Name[50])
{
    records *current = Head ;
    records *last = Head ;
    while (current!=NULL)
    {
        if(current->ID==ID) 
        {
            printf("\n*********** Existing user id **************\n");
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

void Add_new_reservation(Reservations *Head,u8 Name[50],u8 slot,u8 ID)
{
    Reservations *current = Head;
    Reservations *last =Head;
    while(current!=NULL)
    {
        if(current->slot == slot)
        {
            printf("**********************************\n");
            printf("****** Already reserved **********\n");
            printf("*** Pleasw choose another slot ***\n");
            printf("**********************************\n");
            return;
        }
        last=current;
        current=current->next;
    }
    Reservations *new_node = (Reservations*)malloc(sizeof(Reservations));
    last->next =new_node;
    strcpy(new_node->Name,Name);
    new_node->ID=ID;
    new_node->slot=slot;
    new_node->next=NULL;
}

void show_reservations(Reservations *Head)
{
    Reservations *current = Head->next;
    printf("\n------------Reserved slots-----------\n");
    while(current!=NULL)
    {
        printf("Slot No.:%d\n",current->slot);
        printf("ID.:%d\n",current->ID);
        printf("-------------------------------");
        current=current->next;
    }
    printf("---------------------------------------\n");

}

void remove_last_reservation(Reservations* head)
{
    /* if there is only one item in the list, remove it */
    if (head->next == NULL) {
        free(head);

    }

    /* get to the second to last node in the list */
    Reservations * current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    /* now current points to the second to last item of the list, so let's remove current->next */
    free(current->next);
    current->next = NULL;

}

void search_patient_record_by_id(records * Head ,u8 ID)
{
    records * current = Head->next ;
    while (current != NULL)
    {
         if (current->ID == ID)
        {
            printf("-----------------Patient Found------------\n");
            printf("User Id:%d\n", current->ID);
            printf("User Age:%d\n", current->Age);
            printf("User Gender:%s\n", current->gender);
            printf("User Name:%s\n", current->Name);
            return;
        }   
        current = current->next;
    }
    printf("-----------No patient found with this ID-----------");
}