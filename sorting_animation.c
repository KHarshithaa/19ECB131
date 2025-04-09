#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For usleep()

#define SIZE 10

void printArray(int arr[], int n, int highlight1, int highlight2) {
    for (int i = 0; i < n; i++) {
        if (i == highlight1 || i == highlight2)
            printf("[%-2d] ", arr[i]); // Highlight swapped elements
        else
            printf(" %-2d  ", arr[i]);
    }
    printf("\n");
}

void bubbleSortAnimated(int arr[], int n) {
    printf("Sorting animation (Bubble Sort):\n\n");
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            printArray(arr, n, j, j + 1);
            usleep(200000); // 0.2 second delay

            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped)
            break;
        printf("\n");
    }

    printf("\nSorted array:\n");
    printArray(arr, n, -1, -1);
}

int main() {
    int arr[SIZE] = {64, 25, 12, 22, 11, 88, 45, 1, 5, 31};
    bubbleSortAnimated(arr, SIZE);
    return 0;
}
