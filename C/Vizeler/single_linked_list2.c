#include <stdio.h>
#include <stdlib.h>
//Creating a Node Structure
struct node
{
    int data;
    struct node *link;    
}*head;


struct node *create_linked_list(int n)
{
    struct node *ptr, *tmp;
    int num, i;

    head = malloc(sizeof(struct node)); 
    
    if (head == NULL) printf("Memory can't be allocated");//Check if head is full
    
    //Getting Inputs
    printf("Enter 1. Data: ");
    scanf("%d", &num);

    head -> data = num;
    head -> link = NULL;

    ptr = head;//Assigning temp pointer for head

    //Assigning other datas
    for (i = 2; i <= n; i++)
    {
        tmp = malloc(sizeof(struct node));
        if (tmp == NULL)
        {
            printf("Memory can not be allocated!");
            break;
        } 
        printf("Enter %d.Data: ", i);
        scanf("%d", &num);
        
        tmp -> data = num;
        tmp -> link = NULL;

        ptr -> link = tmp;
        ptr = ptr -> link;
    }
    return head;
};

struct node *get_last_node(struct node *head)
{
    struct node *temp;
    temp = head;

    while (temp -> link != NULL)
    {
        temp = temp -> link;
    }
    return temp;
};

void add_to_end(struct node *ptr, int newData)
{
    struct node *temp = malloc(sizeof(struct node));
    temp -> data = newData;
    temp -> link = NULL;

    ptr -> link = temp;
}

struct node *add_to_start(struct node *head, int newData)
{
    struct node *temp = malloc(sizeof(struct node));
    temp -> data = newData;
    temp -> link = head;
    
    return temp;
};

void add_to_pos(struct node *head, int pos, int newData)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr -> data = newData;
    ptr -> link = NULL;
    
    struct node *temp;  
    temp = head;
    
    while(pos >= 0)
    {
        temp = temp -> link;
        pos--;
    }
    ptr -> link = (temp -> link) -> link;
    temp -> link = ptr;

    ptr -> link = temp->link->link;
    temp -> link = ptr;
}
struct node *delete_first_node(struct node *head)
{
    if (head == NULL) printf("The last is already empty!");
    struct node *temp = head;
    head = head -> link;

    free(temp);
    temp = NULL;
    return head;
}

struct node* delete_last_node(struct node *head)
{
    struct node *temp = head;
    while (temp -> link -> link != NULL)
        temp = temp -> link;
    free(temp -> link);
    temp -> link = NULL;
    return temp;
}

struct node* delete_selected_node(struct node *head, int pos)
{
    struct node *temp = head;
    struct node *temp2;
    if (head == NULL) printf("This list is empty!");
    if (pos == 1){
        head = delete_first_node(head);
        return head;
    }
    else {
        
        while (pos-2 != 0)
        {
            temp = temp -> link;
            pos--;
        }
        temp2 = temp -> link;
        temp -> link = temp -> link -> link;
        free(temp2);
        temp2 = NULL;
        return head;
    }
}
int search_element(struct node* head, int searchData)
{
    struct node *temp = head;
    int count = 0;
    while (temp -> data != searchData)
    {
        temp = temp -> link; 
        count++;
    }
    return count;
}

void print_list(struct node *head)
{
    struct node *temp;
    if (head == NULL) printf("This list is empty!\n");
    
    temp = head;
    int count = 1;
    while(temp != NULL)
    {
        printf("%d.Data: %d\n", count, temp -> data);
        temp = temp -> link;
        count++;
    }
}

int main(){
    //Creating linked list
    int size, ans;
    printf("Please enter size of the linked list: ");
    scanf("%d", &size);

    print_list(create_linked_list(size));
    //Adding new data to the head and updating head
    //int newData = 5;
    //head = add_to_start(head, newData);

    printf("\n\n");

    //printf("%d", get_last_node(head));
    struct node *lastNode = get_last_node(head);
    //add_to_end(lastNode, 4);

    //add_to_pos(head, 2, 7);
    //head = delete_first_node(head);

    //lastNode = delete_last_node(head);
    
    //Deleting Particular Element
    /*
    printf("Which element that you want to delete?: ");
    scanf("%d", &ans);
    head = delete_selected_node(head, ans);
    */

    //Searching Particular Data;

    printf("Which data that you want to search?: ");
    scanf("%d", &ans);

    printf("Searched data: %d\nElement of searching data: %d",ans ,search_element(head, ans));


    //print_list(head);


}