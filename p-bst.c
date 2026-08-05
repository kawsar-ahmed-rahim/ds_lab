# include <stdio.h>
# include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
}

struct Node *createNode(int data)