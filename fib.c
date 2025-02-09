#include <stdio.h>

int fib(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    printf("\nEnter A Number: ");
    scanf("%d", &n);
    printf("\nThe %dth Fibonacci number: %d\n", n, fib(n));
    
    printf("\nThe Fibonacci sequence:\n");
    for(int i = 0; i <= n; i++) {
        printf("%d ", fib(i));
    }
    printf("\n");

    return 0;
}
