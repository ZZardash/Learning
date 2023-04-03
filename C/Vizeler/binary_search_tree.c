#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
}*root, *temp;
struct node* new_node(int data)
{
    temp = malloc(sizeof(struct node));
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}
struct node* insert_data(struct node *root, int newData){
    if (root == NULL) 
        return new_node(newData);
    else if(newData > root -> data) 
        root -> right = insert_data(root -> right, newData);
    else 
        root -> left = insert_data(root -> left, newData);
    return root;
}
void inorder(struct node *root){
    if (root == NULL) return;
    inorder(root -> left);
    printf("%d", root -> data);
    inorder(root -> right);
}
int main(){
    root = malloc(sizeof(struct node));
    root = new_node(5);
    temp = root;
    temp = insert_data(root, 1);
    temp = insert_data(root, 2);
    temp = insert_data(root, 3);
    temp = insert_data(root, 4);
    inorder(root);
}