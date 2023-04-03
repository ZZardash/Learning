#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
}*head, *ptr;


struct node* create_new_list(int listSize)
{
    struct node *temp;
    struct node *ptr;

    int newData;

    head = malloc(sizeof(struct node));
    printf("Enter 1.data: ");
    scanf("%d", &newData);
    
    head -> data = newData;
    head -> link = NULL;

    temp = head;
    for (int i = 2; i <= listSize; i++)
    {
        ptr = malloc(sizeof(struct node));
        printf("Enter %d.data: ", i);
        scanf("%d", &newData);
        
        ptr -> data = newData;
        ptr -> link = NULL;
        temp -> link = ptr;

        temp = temp -> link;
    }
    temp -> link = head;
    return head;
};

void show_all_list(struct node *head){
    struct node *temp = head;
    while(temp -> link != head){
        printf("%d", temp -> data);
        temp = temp -> link;
    }
    printf("%d", temp -> data);
}

struct node *delete_odd(struct node *head)
{
    struct node *temp = head;
    while((temp->data) - (temp->link->data) == (-1))
        temp = temp-> link;
    struct node *silinecek = temp->link;
    temp -> link = temp->link->link;
    free(silinecek);
    return head;
}

int aritmetik_ortalama(struct node *head){
    struct node *temp = head;
    int count = 0, sum = 0;
    while(temp -> link != head)
    {
        sum += temp -> data;
        count++;
        temp = temp -> link;
    }
    sum += temp -> data;
    count++;
    int ortalama = sum/count;
    return ortalama;
}

int main(){
    head = create_new_list(5);
    //head = delete_odd(head);
    show_all_list(head);
    int ortalama = aritmetik_ortalama(head);
    
    printf("\nOrtalama:%d", ortalama);


}