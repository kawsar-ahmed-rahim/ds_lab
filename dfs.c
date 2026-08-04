//! DFS traversal using adjacency list
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node *next;
};

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

void addEdge(struct Node *adjList[], int source, int destination){
    struct Node *newNode;

    newNode = createNode(destination);
    newNode->next = adjList[source];
    adjList[source] = newNode;

    newNode = createNode(source);
    newNode->next = adjList[destination];
    adjList[destination] = newNode;
}

void dfs(struct Node *adjList[], int visited[], int currentVertex){
    visited[currentVertex] = 1;
    printf("%d ", currentVertex);

    // visit all the adjacent vertices
    struct Node *temp = adjList[currentVertex];
    while(temp != NULL){
        int adjVertex = temp->vertex;
        if(visited[adjVertex] == 0){
            dfs(adjList, visited, adjVertex);
        }
        temp = temp->next;
    }
}

int main(){
    int vertices, edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    struct Node *adjList[MAX];
    for(int i = 0; i < vertices; i++){
        adjList[i] = NULL;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for(int i = 0; i < edges; i++){
        scanf("%d %d", &u, &v);
        addEdge(adjList, u, v);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    int visited[MAX] = {0};
    dfs(adjList, visited, start);
    printf("\n");

    return 0;
}