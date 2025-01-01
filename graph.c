#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10

int numVertices;
int adjMatrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

void bfs(int startVertex) {
    int queue[MAX_VERTICES], front = 0, rear = -1, currentVertex;

    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    while (front <= rear) {
        currentVertex = queue[front++];

        printf("Visited vertex: %d\n", currentVertex);

        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void dfs(int startVertex) {
    visited[startVertex] = 1;
    printf("Visited vertex: %d\n", startVertex);

    for (int i = 0; i < numVertices; i++) {
        if (adjMatrix[startVertex][i] && !visited[i]) {
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
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }
}

int main() {
    int startVertex, choice;

    while (1) {
        inputGraph(&startVertex);

        resetVisited();

        printf("\nChoose the search algorithm:\n");
        printf("1 ---> Breadth-First Search (BFS)\n"
               "2 ---> Depth-First Search (DFS)\n"
               "3 ---> Exit\n");
        printf("Enter your choice (1, 2, 3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: bfs(startVertex);
                    break;
            case 2: dfs(startVertex);
                    break;
            case 3: exit(0);
            default: printf("\nInvalid choice\n");
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
