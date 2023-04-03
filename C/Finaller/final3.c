#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
}*root;

//Creating new node
struct node* newNode(int newData){
    struct node *new = malloc(sizeof(struct node));
    new -> data = newData;
    new -> right = NULL;
    new -> left = NULL;
    return new;
}

//Printing algorithms
void preorder(struct node *root){
    if (root != NULL){
        printf("%d ", root -> data);
        preorder(root -> left);
        preorder(root -> right);
    }
}

void inorder(struct node *root){
    if (root != NULL){
        inorder(root -> left);
        printf("%d ", root -> data);
        inorder(root -> right);
    }
}

void postorder(struct node *root){
    if (root != NULL){
        postorder(root -> left);
        postorder(root -> right);
        printf("%d ", root -> data);
    }
}

//Count - Max Depth - Min - Max 

int countOf(struct node *root){
    if (root == NULL) return 0;
    return 1 + countOf(root -> left) + countOf(root -> right);
}

int maxDepth(struct node *root){
    if (root == NULL) return 0;
    int lDepth = maxDepth(root -> left);
    int rDepth = maxDepth(root -> right);

    if(lDepth > rDepth)
        return (lDepth + 1);
    else 
        return (rDepth + 1);    
}

struct node* findMax(struct node *root){
    if (root == NULL)
        return root;
    
    if (root -> right != NULL) 
        return findMax(root -> right);

    return root;
}






int main(){
    //Creating new tree
    root = newNode(5);
    root -> right = newNode(6);
    root -> left = newNode(3);
    
    //Printing tree with inorder
    printf("------In Order-------\n");
    inorder(root);
    printf("\n");
    
    printf("------Pre Order-------\n");
    preorder(root);
    printf("\n");

    printf("------Post Order-------\n");
    postorder(root);
    printf("\n");

    printf("%d", maxDepth(root));

}