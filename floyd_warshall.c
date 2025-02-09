#include <stdio.h>

#define INF 9999

void floydWarshall(int n, int d[n][n]) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int d[n][n];
    printf("Enter adjacency matrix (999 for INF and 0 for no path to itself):\n");
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &d[i][j]);

            if (d[i][j] == 0 && i != j) {
                d[i][j] = INF;
            }
        }
    }

    floydWarshall(n, d);

    printf("Shortest path matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i][j] == INF) {
                printf("INF\t");
            } else {
                printf("%d\t", d[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
