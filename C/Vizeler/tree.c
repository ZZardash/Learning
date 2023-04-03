#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
}*root;

struct node* newNode(int newData){
    struct node *nNode = malloc(sizeof(struct node));
    nNode -> data = newData;
    nNode -> left = NULL;
    nNode -> right = NULL;
    return nNode;
};

int countTree(struct node* root){
   if (root == NULL) return 0;
   return 1 + countTree(root -> left) + countTree(root -> right); 
}

int rowCount(struct node *root){
    int count = 0;
    struct node *temp = root;
    while(temp -> left != NULL)
    {
        temp = temp -> left;
        count++;
    }    
    return count;
}

int maxDepth(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
 
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

void preorder(struct node *root)
{
    if (root != NULL){
        printf("%d", root -> data); 
        preorder(root ->left);
        preorder(root -> right);
    }
}

void inorder(struct node *root)
{
    if (root != NULL){
        inorder(root ->left);
        printf("%d", root -> data); 
        inorder(root -> right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL){
        postorder(root ->left);
        postorder(root -> right);
        printf("%d", root -> data); 
    }
}

struct node* search(struct node *root, int data)
{
    if (root == NULL || root -> data == data)
        return root;
    if (data > root -> data)
        return search(root -> right, data);
    else
        return search(root -> left, data);
}

struct node* findMin(struct node *root){
    if (root == NULL) return root;
    if (root -> left != NULL) return findMin(root -> left);
    return root;
}

struct node* findMax(struct node *root){
    if (root == NULL) return root;
    if (root -> right != NULL) return findMax(root -> right);
    return root;
}  

struct node *deleteNode(struct node *root, int target){
    if (root == NULL){
        free(root);
        return NULL;
    }
    else if (target > root -> data) 
        return deleteNode(root -> right, target);
    
    else if (target < root -> data) 
        return deleteNode(root -> left, target);
    
    else{
        printf("\n%d\n", root -> data);
        //No child
        if (root -> left == NULL && root -> right == NULL) 
        {
            free(root);
            return NULL;
        }

        //One child
        else if (root -> left == NULL || root -> right == NULL)
        {
            struct node *temp;
            if (root -> left == NULL) temp = root -> right;
            else temp = root -> left;
            
            free(root);
            return temp;
        } 

        //Two childs
        else{
            struct node *temp = findMin(root -> right);
            root -> data = temp -> data;
            root -> right = deleteNode(root -> right, temp -> data);
        }   
    }           
    return root;
}

int main(){
    //Creating BINARY SEARCH TREE
    root = newNode(3);
    root -> left = newNode(2);
    root -> right = newNode(6);

    root -> right -> left = newNode(5);
    root -> right -> right = newNode(7);

    inorder(root);
    printf("\n\n");
    preorder(root);
    printf("\n\n");
    postorder(root);
}


