//! BFS traversal using adjacency list
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node *next;
};

struct Node *createNode(int v){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// add edge u -> v (undirected: also add v -> u)
void addEdge(struct Node *adjList[], int u, int v){
    struct Node *newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

void bfs(struct Node *adjList[], int vertices, int start){
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    // insert starting vertex into queue
    queue[rear++] = start;
    visited[start] = 1;

    while(front < rear){
        // remove a vertex from the front of the queue
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        struct Node *temp = adjList[currentVertex];
        while(temp != NULL){
            int adjVertex = temp->vertex;
            if(visited[adjVertex] == 0){
                queue[rear++] = adjVertex;
                visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
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

    printf("BFS traversal: ");
    bfs(adjList, vertices, start);

    return 0;
}