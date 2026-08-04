struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
}

struct maxHeap{
    int size;
    struct node *root;
}

struct maxHeap *createHeap(){
    struct maxHeap *heap=(struct maxHeap*)malloc(sizeof(struct maxHeap));

    if(heap==NULL){
        printf("memory allocation failed");
        exit(Exit_failure);
    }
    heap->root=null;
    heap->size=0;
    return heap;

}

struct Node *createNode(int value){
    newNode->data=value;
    newNode->left=null;
    newNode->right=null;
    newNode->parent=null;
}

void swapData(struct node *first, struct node *second){
    int temp=first->data;
    first->data=second->data;
    second->data=temp;
}

struct Node *getPosition(struct MaxHeap,int position){
    if(position<1 || heap->root==Null)
    return null;
    struct Node *current=heap->root;
    int path[32];
    int length=0;
    while(position>1){
        path[length]=position%2;
        length++;
        position /=2;
    }

}
// folow the path from top to bottom
for(int i=length-1; i>0;i--){
    if(path[0]==0){
        current=current->left;
    }else {
        current=current->right;
    }
    return current;
}
// restore the max heap property by moving upward
void heapify(struct Node *node){
    while(node->parent!=null){
        swapData(node, node->parent);
        node = node->parent;
    }
}

// insert a value into maxheap

void insert(struct maxheap *heap,int value){
    struct Node *newNode = createNode(value);
}