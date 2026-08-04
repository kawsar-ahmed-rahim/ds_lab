//! Graph implementation using adjacency list
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node *next;
};

// create a new node
struct Node *createNode(int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->vertex = value;
    newNode->next = NULL;
    return newNode;
}

// add an undirected edge between source and destination
void addEdge(struct Node *adjList[], int source, int destination){
    struct Node *newNode;

    // add destination to source's list
    newNode = createNode(destination);
    newNode->next = adjList[source];
    adjList[source] = newNode;

    // add source to destination's list
    newNode = createNode(source);
    newNode->next = adjList[destination];
    adjList[destination] = newNode;
}

// print the adjacency list
void display(struct Node *adjList[], int vertices){
    for(int i = 0; i < vertices; i++){
        printf("Vertex %d: ", i);
        struct Node *current = adjList[i];
        while(current != NULL){
            printf("%d ", current->vertex);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// free all allocated nodes
void freeGraph(struct Node *adjList[], int vertices){
    for(int i = 0; i < vertices; i++){
        struct Node *current = adjList[i];
        while(current != NULL){
            struct Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main(){
    struct Node *adjList[MAX] = {NULL};
    int vertices, edges, source, destination;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    if(vertices <= 0 || vertices > MAX){
        printf("Invalid number of vertices\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter %d edges (source destination):\n", edges);
    for(int i = 0; i < edges; i++){
        scanf("%d %d", &source, &destination);

        if(source < 0 || source >= vertices || destination < 0 || destination >= vertices){
            printf("Invalid edge: %d %d\n", source, destination);
            continue;
        }
        addEdge(adjList, source, destination);
    }

    printf("\nAdjacency List:\n");
    display(adjList, vertices);

    freeGraph(adjList, vertices);

    return 0;
}