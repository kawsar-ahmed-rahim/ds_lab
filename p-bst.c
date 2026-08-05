# include <stdio.h>
# include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int data) {
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left=newNode->right=NULL;

    return newNode;
}

struct Node *insert(struct Node *root, int data) {
    if(root == NULL){
        return createNode(root);
    }
    if(data< root->data){
        root->left = insert(root->left,data);
    } else if(data> root->data){
        root->right = insert(root->right,data);
    }
    return root;
}

void inorder(struct Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}

void preorder(struct Node *root) {
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root) {
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void freeTree(struct Node *root){
    if(root == NULL){
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(){
     int n, data;
    struct Node *root = NULL;

    printf("How many values? ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    freeTree(root);

    return 0;
}