#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
}*head;

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
    return head;
};

struct node *add_beg(struct node *head, int newData){
    struct node *temp = malloc(sizeof(struct node));
    temp -> data = newData;
    temp -> link = head;
    head = temp;
    return head;
};

struct node *add_end(struct node *head, int newData){
    struct node *ptr = malloc(sizeof(struct node));
    ptr -> data = newData;
    ptr -> link = NULL;

    struct node *temp = head;
    while(temp -> link != NULL) temp = temp -> link;
    temp -> link = ptr;
    return ptr;
};

struct node *delete_head(struct node *head){
    struct node *temp = head;
    head = head -> link;

    free(temp);
    temp = NULL;
    return head;
};

struct node* delete_last(struct node *ptr){
    struct node *temp = head;
    while (temp -> link -> link != NULL)
        temp = temp -> link;
    free(temp -> link);
    temp -> link = NULL;
    return temp;
};

void show_all_list(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d", temp -> data);
        temp = temp -> link;
    }
}



int main(){
    struct node *ptr;
    head = create_new_list(5);
    //aritmetik ortalama/düzen bozan bulma
    /*
    show_all_list(head);
    head = add_beg(head, 6);
    printf("\n");
    show_all_list(head);
    printf("\n");

    show_all_list(head);
    */
    printf("\n");

    ptr = add_end(head, 197);
    head = delete_head(head);
    show_all_list(head);
    ptr = delete_last(ptr);
    printf("\n");
    show_all_list(head);

}