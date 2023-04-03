#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *link;
}*head, *temp;

struct node *create_list(int count){
    struct node *temp, *ptr;
    int newData;
    
    struct node *head = malloc(sizeof(struct node));
    printf("Enter 1.data: ");
    scanf("%d", &newData);
    head -> prev = NULL;
    head -> data = newData;
    head -> link = NULL; 

    temp = head;
    for (int i = 2; i <= count; i++)
    {
        ptr = malloc(sizeof(struct node));
        printf("Enter %d.data: ", i);
        scanf("%d", &newData);
        ptr -> prev = temp;
        ptr -> data = newData;
        ptr -> link = NULL;

        temp -> link = ptr;
        temp = temp -> link; 
    }
    temp -> link = head;
    return head;
}
    

void print_list(struct node *temp)
{
    if (temp -> link == head){
        printf("%d", temp -> data);
        return;
    } 
    printf("%d", temp -> data);
    print_list(temp -> link);
}

struct node* insert_head(struct node *head, int key)
{
    if (head == NULL)
    {
        head = malloc(sizeof(struct node));        
        head -> data = key;
        head -> prev = NULL;
        head -> link = NULL; 
    }
    else {
        temp = malloc(sizeof(struct node));
        temp -> data = key;
        head -> prev -> link = temp;
        temp -> link = head;        
        head -> prev = temp;
        temp -> prev = head -> prev -> prev;

    }
}


int main(){
    head = create_list(1);
    temp = head;
    print_list(temp);

}
