#include <stdio.h>

// Function to generate Fibonacci series up to n terms
void fibonacci_iterative(int n) {
    if (n <= 0) {
        printf("Enter a positive number.\n");
        return;
    }

    int fib[n]; // Array to store Fibonacci terms
    fib[0] = 0;

    if (n > 1)
        fib[1] = 1;

    printf("Fibonacci Series (%d terms):\n", n);
    for (int i = 0; i < n; i++) {
        if (i == 0 || i == 1)
            printf("%d ", fib[i]);
        else {
            fib[i] = fib[i - 1] + fib[i - 2];
            printf("%d ", fib[i]);
        }
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    fibonacci_iterative(n);

    return 0;
}
