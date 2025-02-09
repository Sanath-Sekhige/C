#include <stdio.h>

int moveCount = 0;

void towerOfHanoi(int n, char S, char D, char T) {
    if (n == 1) {
        moveCount++;
        printf("Move disk 1 from peg %c to peg %c\n", S, D);
        return;
    }
    towerOfHanoi(n - 1, S, T, D);
    moveCount++;
    printf("Move disk %d from peg %c to peg %c\n", n, S, D);
    towerOfHanoi(n - 1, T, D, S);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'S', 'D', 'T');
    printf("\nTotal number of moves: %d\n", moveCount);
    return 0;
}
