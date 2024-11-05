#include <stdio.h>

int GCD(int a, int b) {
    if(a == b) return a;
    if(a > b) return GCD(a - b, b);
    if(a < b) return GCD(a, b - a);
}

int main() {
    int a, b;
    printf("Enter a number: ");
    scanf("%d", &a);
    printf("\nEnter a number: ");
    scanf("%d", &b);
    printf("GCD of %d and %d = %d", a, b, GCD(a, b));
    return 0;
}