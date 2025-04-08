#include <stdio.h>

void insert(int arr[], int *n, int pos, int val) {
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    (*n)++;
}

void delete(int arr[], int *n, int pos) {
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

int main() {
    int arr[100] = {1, 2, 3, 4, 5}, n = 5;

    printf("Original Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    insert(arr, &n, 2, 99);
    printf("\nAfter Insertion at index 2: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    delete(arr, &n, 3);
    printf("\nAfter Deletion at index 3: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    return 0;
}
