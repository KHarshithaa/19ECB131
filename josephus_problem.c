#include <stdio.h>

// Function to find the safe position using recursion
int josephus(int n, int k) {
    if (n == 1)
        return 0;
    else
        return (josephus(n - 1, k) + k) % n;
}

int main() {
    int n, k;

    printf("Enter total number of people (n): ");
    scanf("%d", &n);
    printf("Enter the step count (k): ");
    scanf("%d", &k);

    int result = josephus(n, k);
    printf("The safe position is: %d\n", result + 1); // +1 for 1-based index

    return 0;
}
