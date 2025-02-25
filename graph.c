#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10

int numVertices;
int adjMatrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

void bfs(int startVertex) {
    int Q[MAX_VERTICES], front = 0, rear = -1, currentVertex;

    visited[startVertex] = 1;
    Q[++rear] = startVertex;

    while(front <= rear) {
        currentVertex = Q[front++];
        printf("\nVisited Vertex %d", currentVertex);
        for(int i = 0; i < MAX_VERTICES; i++) {
            if(adjMatrix[currentVertex][i] && !visited[i]) {
                Q[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void dfs(int startVertex) {
    visited[startVertex] = 1;
    printf("\nVisited Vertex %d", startVertex);
    for(int i = 0; i < MAX_VERTICES; i++) {
        if(adjMatrix[startVertex][i] && !visited[i]) {
            dfs(i);
        }
    }
}

void inputGraph(int *startVertex) {
    printf("\nEnter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &numVertices);

    printf("\nEnter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    printf("\nThe adjacency matrix is:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the source vertex (0 to %d): ", numVertices - 1);
    scanf("%d", startVertex);
}

void resetVisited() {
    for(int i = 0; i < MAX_VERTICES; i++) {
        visited[i] = 0;
    }
}

int main() {
    int startVertex, choice, continueInput;
    do {
        inputGraph(&startVertex);

        resetVisited();

        printf("\nChoose the search algorithm:\n");
        printf("1 ---> Breadth-First Search (BFS)\n"
               "2 ---> Depth-First Search (DFS)\n"
               "3 ---> Exit\n");
        printf("Enter your choice (1, 2, 3): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1 : bfs(startVertex);
                     break;
            case 2 : dfs(startVertex);
                     break;
            case 3 : exit(0);
            default: printf("\nINVALID CHOICE\n");
        }

        printf("\nReachability status:\n");
        for (int i = 0; i < numVertices; i++) {
            printf("\nVertex %d is %s from %d", i, visited[i] ? "Reachable" : "Not Reachable", startVertex);
        }
        printf("\nDo you want to continue? (1 = Yes | 0 = No): ");
        scanf("%d", &continueInput);
    } while(continueInput);
    return 0;
}