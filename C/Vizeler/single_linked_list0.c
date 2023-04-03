#include <stdio.h> //Required for standard I/O
#include <stdlib.h> //Required for malloc() function
//Self Referantial Structure
struct abc
{
    int a;  
    char b;
    struct abc *self;  
};

//Creating a Node Structure
struct node
{
    int data;
    struct node *link;    
};

//Calculating node number of a linked list
int count_of_nodes(struct node *head)
{
    int count = 0;
    if (head == NULL)
     printf("Linked list is empty!");

    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr -> link;
    }
    return count;
}
//Adding node to the beggining of the linked list
struct node* add_beg(struct node* head, int newData)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr -> data = newData;
    ptr -> link = NULL;

    ptr -> link = head;
    head = ptr;//Declare new head
    return head;
}
//Adding node to the beggining 2nd Method
void add_beg_2(struct node **head, int d)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr -> data = d;
    ptr -> link = NULL;

    ptr -> link = *head;
    *head = ptr;
}

//Adding node to the end
struct node* add_end(struct node *ptr, int newData)
{
    struct node *temp = malloc(sizeof(struct node));
    temp -> data = newData;
    temp -> link = NULL;

    ptr -> link = temp;  
    return temp;
}
//Inserting node at a certain position
void add_at_poss(struct node* head, int newData, int pos)
{
    struct node *ptr = head;
    struct node *ptr2 = malloc(sizeof(struct node));

    ptr2 -> data = newData;
    ptr2 -> link = NULL;

    pos--;
    while(pos != 1)
    {
        ptr = ptr -> link;
        pos--;        
    }
    ptr2 -> link = ptr -> link;
    ptr -> link = ptr2;
}
//Deleting the first node of the linked list
struct node* delete_first_node(struct node *head)
{
    if (head == NULL) printf("List is already empty!");
    
    struct node *temp = head;
    head = head -> link;//Shifting the head
    free(temp);//Free mem from the RAM
    temp = NULL;
    
    return head;
}

//Deleting the last node of the linked list
void delete_last_node(struct node *head)
{
    if (head == NULL) printf("List is already empty!");
    
    else if (head->link == NULL)
    {
        free(head);
        head = NULL;
    }

    else
    {
        struct node *temp = head;
        struct node *temp2 = head;
        while(temp -> link != NULL)
        {
            temp2 = temp;
            temp = temp -> link;
        }
        temp2 -> link = NULL;//temp2 for the NULL the last nodes link
        free(temp); //temp for the delete the last nodes data and free it
        temp = NULL;
    }
}
//Deleting the last node of the list with single pointer
void delete_last_node_2(struct node *head)
{
    if (head == NULL) printf("List is already empty!");

    else if (head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    else 
    {
        struct node *temp = head;
        while(temp -> link -> link != NULL)
        {
            temp = temp -> link;
        }
        free(temp -> link);
        temp -> link = NULL;
    }
}
//Deleting the certain node from the linked list 
struct node* delete_certain_node(struct node *head, int pos)
{
    struct node *ptr = head;
    struct node *ptr2 = head;
    
    if (head == NULL) printf("List is already empty!");
    
    else if (pos == 1)
    {
        head = ptr2 -> link;
        free(ptr2);
        ptr2 = NULL;
    }
    
    else
    {
        pos--;
        while(pos != 0)
        {
            ptr = ptr2;
            ptr2 = ptr2 -> link;
            pos--;        
        }
        ptr->link = ptr2 -> link;
        free(ptr2);
        ptr2 = NULL;
    }
    return head;
}

//Deleting the entire linked list
struct node* delete_entire_list(struct node *head)
{
    int count = count_of_nodes(head);
    while (count > 0)
    {
        struct node *temp = head;
        temp = temp -> link;
        free(head);
        head = temp;
        count--;
    }
    return head;
}

int main(){
    int d1, d2;
    printf("Please enter data 1:");
    scanf(" %d", d1);
    
    printf("Please enter data 2:");
    scanf(" %d", d2);

    //Creating "head" Node
    struct node *head = malloc(sizeof(struct node)); 
    head -> data = d1; 
    head -> link = NULL;
    
    //Creating "ptr" Node
    struct node *ptr = malloc(sizeof(struct node));
    ptr -> data = d2;
    ptr -> link = NULL;

    //Connecting the nodes
    head -> link = ptr;
    
    //Easy way to create another node and linking
    /* 
    ptr = malloc(sizeof(struct node));//Reuse this pointer for create a node    
    ptr->data = 3;
    ptr->link = NULL;
    head->link->link = ptr;
    

    printf("%d\n", head -> data);//First node data
    printf("%d\n", head->link->data);//Second node data
    printf("%d\n", ptr->data);//Third node data
    
    printf("%d\n", count_of_nodes(head));
    */

    //Adding new node to the list
    int data = 3;
    head = add_beg(head, data);//Updating the head 
    add_beg_2(&head, data);//2nd Method
     
    //Reduce the time with updating ptr method
    ptr = add_end(ptr, 23);
    ptr = add_end(ptr, 24);
    ptr = add_end(ptr, 25);  

    //Inserting  certain position
    add_at_poss(head, 31, 2);
    ptr = head;

    //Deleting first node
    head = delete_first_node(head);
    ptr = head;
    
    //Delete last node
    delete_last_node(head);//No need to return the head
    delete_last_node_2(head);

    //Delete certain node
    head = delete_certain_node(head, 1);
    ptr = head;

    //Deleting entire list
    //head = delete_entire_list(head);
    //ptr = head;
    //if (head == NULL) printf("Linked list succesfully deleted!");

    while(ptr != NULL)
    {
        printf("%d\n", ptr -> data);
        ptr = ptr -> link;
    }  
    
    return 0;
}
