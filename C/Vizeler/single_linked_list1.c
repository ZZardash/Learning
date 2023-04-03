#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void add_data(struct node *head, int newData)
{
    if (head == NULL)
    {
        head -> data = newData;
        head -> link = NULL;
    }
    else 
    {
        struct node *temp;
        while(temp != NULL)
        {
            temp = temp -> link;
        }
        temp -> data = newData;
        temp -> link = NULL;
    }
}

void sondan_sil(struct node *head){
    struct node *temp;
    temp = head;
    while (temp -> link -> link == head)
    {
        temp -> link = head;
        free(temp -> link);
        temp -> link = NULL;
    }
        temp = temp -> link;
}

void yazdir(struct node *head)
{
    int i = 1;
    struct node *temp = head;
    while (temp -> link == head)
    {
        printf("%d", temp -> link);
    }
}


int main(){
    struct node *head = malloc(sizeof(struct node));
    head -> data = 5;
    head -> link = NULL;

    struct node *ptr = malloc(sizeof(struct node));
    ptr -> data = 10;
    ptr -> link = NULL;

    head -> link = ptr;
    ptr -> link = head;
    printf("\n");

    yazdir(head);
/*
    sondan_sil(head);

    printf("\n\n");
    yazdir(head);
*/


}