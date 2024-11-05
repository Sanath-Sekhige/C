#include <stdio.h>

int ackreman(int a, int b) {
    if(a == 0) return b + 1;
    if(b == 0) return ackreman(a - 1, 1);
    return ackreman(a - 1, ackreman(a, b - 1));
}

int main() {
    int a, b;
    printf("Enter a number: ");
    scanf("%d", &a);
    printf("\nEnter a number: ");
    scanf("%d", &b);
    printf("ackreman(%d, %d) = %d", a, b, ackreman(a, b));
    return 0;
}