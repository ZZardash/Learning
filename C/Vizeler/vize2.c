#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *link;
}*head;

struct node *create_list(int count){
    struct node *temp, *ptr;
    int newData;

    head = malloc(sizeof(struct node));
    printf("Enter 1.data : ");
    scanf("%d", &newData);
    head -> prev = NULL;
    head -> data = newData;
    head -> link = NULL;

    temp = head;
    for (int i = 2; i <= count; i++)
    {
        ptr = malloc(sizeof(struct node));
        printf("Enter %d.data :", i);
        scanf("%d", &newData);
        ptr -> prev = temp;
        ptr -> data = newData;
        ptr -> link = NULL;
        
        temp -> link = ptr;
        temp = temp -> link;
    }
    return head;
};

struct node* last_node(struct node *head){
    struct node *temp = head;
    while(temp -> link != NULL) temp = temp -> link;
    return temp;
}

struct node* last_node_rec(struct node *head){
    if (head -> link == NULL) return head;
    return last_node_rec(head -> link);
}

void show_list(struct node *head){
    struct node *temp = head;
    if (temp == NULL) printf("Liste boş");
    while(temp != NULL)
    {
        printf("%d", temp -> data);
        temp = temp -> link;
    }
}

void show_list_rec(struct node *head)
{
    if (head == NULL) return;
    printf("%d", head -> data);
    show_list_rec(head -> link);
}

void show_list_rec_reversed(struct node *head)
{
    if (head != NULL)
    {
        show_list_rec_reversed(head -> link);
        printf("%d", head -> data);
    }
}

void show_prev_rec(struct node *ptr)
{
    if (ptr == NULL) return;
    else {
        printf("%d", ptr -> data);
        show_prev_rec(ptr -> prev);
    }
}

void delete_node_rec(struct node *head, int data){
    if (head -> link -> data == data){
        struct node *temp = head -> link;
        head->link = head->link->link;
        free(temp);
        temp = NULL;
        return;
    }
    delete_node_rec(head->link, data);
}

struct node* search_element(struct node *head, int key)
{
    if (head == NULL)
    if (head -> data == key) return head;
    return search_element(head ->link, key);
};



int count_rec(struct node *head)
{
    if (head == NULL) return 0;
    return count_rec(head -> link) + 1; 
}

int find_max_rec(struct node *head)
{
    int max = head -> data;
    if(head -> link == NULL){
        return max;
    }
    else{
        if(max <= find_max_rec(head -> link)){
           max = head -> data;
        }
        else return max;
    }
    return find_max_rec(head -> link);
}

int find_min_rec(struct node *head)
{
    int min = head -> data;
    if(head -> link == NULL){
        return min;
    }
    else{
        if(min >= find_max_rec(head -> link)){
           min = head -> data;
        }
        else return min;
    }
    return find_min_rec(head -> link);
}

struct node *insert_pos_rec(struct node *head, int pos)
{
    if(head ){

    }
}




int main(){
    head = create_list(5);
    //show_list(head);
    struct node *ptr;
    /*
    show_list_rec(head);//1,2,3,4,5
    ptr = last_node_rec(head);
    printf("\n");
    //show_list_rec_reversed(head);
    show_prev_rec(ptr);//5,4,3,2,1
    delete_node_rec(head, 3);//3 Deleted
    printf("\n");
    show_list(head);//1,2,4,5
    printf("\n");
    show_prev_rec(ptr);//5,4,3,2,1
    */
    //ptr = search_element(head, 5);
    //printf("\n%d", count_rec(head));
    /*
    printf("%d", find_max_rec(head));
    printf("\n%d", find_min_rec(head));
    */

    delete_all_list_rec(head);
    show_list(head);

}