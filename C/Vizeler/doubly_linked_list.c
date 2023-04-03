#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *link;
};

struct node *add_data(struct node *ptr, int newData)
{
    struct node *tmp = malloc(sizeof(struct node));
    ptr -> link = tmp;
    tmp -> prev = ptr;
    tmp -> data = newData;
    tmp -> link = NULL;

    ptr = tmp;
    return ptr;
}; 

struct node *create_list()
{
    int number, size;
    struct node *head = malloc(sizeof(struct node));
    struct node *ptr;

    printf("Enter size of the list: ");
    scanf("%d", &size);

    printf("Enter 1.Data: ");
    scanf("%d", &number);

    head -> prev = NULL;
    head -> data = number;
    head -> link = NULL;

    ptr = head;

    for (int i = 2; i <= size; i++)
    {
        printf("Enter %d.Data: ", i);
        scanf("%d", &number);
        ptr = add_data(ptr, number);
    }
    return head;
};


struct node* last_index_of(struct node *head)
{
    struct node *tmp;
    tmp = head;

    while (tmp -> link != NULL)
    {
        tmp = tmp -> link;
    }
    return tmp;
}


int size_of(struct node *head)
{
    struct node *tmp;
    int count;

    tmp = head;
    while (tmp != NULL)
    {
        tmp = tmp -> link;
        count++;
    }

    return count;
}

void delete_last_node(struct node *ptr)
{
    free(ptr);
    ptr = NULL;
}

void print_reversed_list(struct node *ptr)
{
    struct node *tmp = ptr;
    while(tmp != NULL)
    {
        printf("Data: %d\n", tmp -> data);
        tmp = tmp -> prev;
    }
}

void print_all_list(struct node *head)
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("Data: %d\n", temp -> data);
        temp = temp -> link;
    }
}



int main(){
    struct node *head;
    struct node *ptr;
    int number, size;

    head = create_list();
    ptr = last_index_of(head);
    size = size_of(head);

    printf("\n\n------NORMAL-----\n");
    print_all_list(head);
    /*
    printf("\n\n------REVERSED------\n");
    print_reversed_list(ptr);
    */
    
    printf("\n\nLAST NODE DELETED (NORMAL)\n");
    delete_last_node(ptr);
    print_all_list(head);
   

}

