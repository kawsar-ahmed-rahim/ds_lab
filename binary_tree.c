//! binary tree
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorder(struct Node *root) {
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node *root) {
    if(root==NULL){
        return;
    }
    preorder(root->data);
    printf("%d ", root->left);
    postorder(root->right);
}

void postorder(struct Node *root) {
    if(root==NULL){
        return;
    }
    postorder(root->left);
    printf("%d ", root->right);
    postorder(root->data);
}

int main(){
    int data;
    scanf("%d", &data);
    printf("%d\n",data);

    struct Node *root = createNode(data);
    root->left = createNode(data - 1);
    root->right = createNode(data + 1);
    printf("%d\n",root->left->data);
    printf("%d\n",root->right->data);



    return 0;
}