#include <stdio.h>

void warshall(int n, int p[n][n]) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                p[i][j] |= (p[i][k] && p[k][j]);
}

int main() {
    int n;
    printf("Vertices: ");
    scanf("%d", &n);
    
    int p[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            scanf("%d", &p[i][j]);
        }
    }

    warshall(n, p);

    for (int i = 0; i < n; i++){
        printf("\n");
        for (int j = 0; j < n; j++){
            printf("%d ", p[i][j]);
        }
    }
}
