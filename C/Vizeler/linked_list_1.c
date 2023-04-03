#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
}*head;

struct node *createList(struct node *head, int n){
    head = malloc(sizeof(struct node));
    //if (head != NULL) printf("List already created!");
    
    struct node *ptr;
    int n_data;
    printf("Enter 1.Data: ");
    scanf("%d", &n_data);

    head -> data = n_data;
    head -> link = NULL;

    ptr = head;
    for (int i = 2; i < n+1; i++)
    {
        struct node *new = malloc(sizeof(struct node));
        printf("Enter %d.Data: ", i);
        scanf("%d", &n_data);
        ptr -> link = new;
        new -> data = n_data;
        ptr = new;
    }
    return head;
};

void insertElement(struct node *head, int pos, int nData){
    struct node *ptr = head;
    while (pos > 1){
        ptr = ptr -> link;
        pos--;
    }

    struct node *new = malloc(sizeof(struct node));
    new -> data = nData;
    new -> link = ptr->link;
    ptr->link = new;
}

void delElement(struct node *head, int pos){
    struct node *ptr = head;
    while (pos > 1){
        ptr = ptr -> link;
        pos--;
    }
    struct node *tmp = ptr->link;
    ptr->link = ptr->link->link;
    tmp = NULL;
    free(tmp);
}


void showElements(struct node *head){
    struct node *ptr = head;
    while(ptr != NULL){
        printf("%d", ptr -> data);
        ptr = ptr -> link;
    }
    printf("\n\n");
}

int size(struct node *head){
    struct node *ptr = head;
    int size = 0;
    while(ptr != NULL){
        size++;
        ptr = ptr -> link;
    }
    return size;
}

int main(){
    head = createList(head, 5);
    showElements(head);
    insertElement(head,2,2);
    showElements(head);
    delElement(head, 2);
    showElements(head);
    int size_a = size(head);
    printf("\n\n%d", size_a); 
}