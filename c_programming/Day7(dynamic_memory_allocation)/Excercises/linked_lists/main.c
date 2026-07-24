#include<stdio.h>
#include<stdlib.h>



typedef struct node{
    int val;
    struct node *next;
} node_t;
void print_list(node_t* head);

int main()
{
    node_t * head = NULL;
    head = (node_t*)malloc(sizeof(node_t));
    if(head == NULL)
    {
        return 1 ;
    }
    head->val=1;
    head->next = (node_t*)malloc(sizeof(node_t));
    head->next->val =2;
    head->next->next=(node_t*)malloc(sizeof(node_t));
    head->next->next->val=3;
    head->next->next->next=NULL;
    print_list(head);
    free(head);
    return 0 ;
}

void print_list(node_t* head)
{
    node_t * current =head ;
    while (current != NULL)
    {
        printf("%d\n",current->val);
        current=current->next;
    }
    
}