#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10

void bfs(int numVertices, int startVertex, int adjMatrix[][MAX_VERTICES], int visited[]) {
    int queue[MAX_VERTICES], front = 0, rear = -1, currentVertex;

    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    printf("\nBreadth-First Search (BFS) starting from vertex %d:\n", startVertex);

    while (front <= rear) {
        currentVertex = queue[front++];

        printf("Visited vertex: %d\n", currentVertex);

        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void dfs(int numVertices, int startVertex, int adjMatrix[][MAX_VERTICES], int visited[]) {
    visited[startVertex] = 1;
    printf("Visited vertex: %d\n", startVertex);

    for (int i = 0; i < numVertices; i++) {
        if (adjMatrix[startVertex][i] == 1 && !visited[i]) {
            dfs(numVertices, i, adjMatrix, visited);
        }
    }
}

void inputGraph(int *numVertices, int adjMatrix[][MAX_VERTICES], int *startVertex) {
    printf("\nEnter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", numVertices);

    printf("\nEnter the adjacency matrix:\n");
    for (int i = 0; i < *numVertices; i++) {
        for (int j = 0; j < *numVertices; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    printf("\nThe adjacency matrix is:\n");
    for (int i = 0; i < *numVertices; i++) {
        for (int j = 0; j < *numVertices; j++) {
            printf("%d\t", adjMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the source vertex (0 to %d): ", *numVertices - 1);
    scanf("%d", startVertex);
}

void resetVisited(int numVertices, int visited[]) {
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }
}

int main() {
    int numVertices, adjMatrix[MAX_VERTICES][MAX_VERTICES], startVertex, visited[MAX_VERTICES] = {0};
    int choice;

    while (1) {
        inputGraph(&numVertices, adjMatrix, &startVertex);

        resetVisited(numVertices, visited);

        printf("\nChoose the search algorithm:\n");
        printf("1 ---> Breadth-First Search (BFS)\n"
                "2 ---> Depth-First Search (DFS)\n"
                "3 ---> Exit\n");
        printf("Enter your choice (1, 2, 3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: bfs(numVertices, startVertex, adjMatrix, visited);
                    break;
            case 2: dfs(numVertices, startVertex, adjMatrix, visited);
                    break;
            case 3: exit(0);
            default: printf("\nInvalid choice, please try again.\n");
        }

        printf("\nReachability status:\n");
        for (int i = 0; i < numVertices; i++) {
            if (visited[i] == 0) {
                printf("Vertex %d is not reachable from vertex %d.\n", i, startVertex);
            } else {
                printf("Vertex %d is reachable from vertex %d.\n", i, startVertex);
            }
        }
    }

    return 0;
}
