#include <stdio.h>

#define MAX 100
int heap[MAX];
int size = 0;

void insert(int val) {
    heap[++size] = val;
    int i = size;

    while (i > 1 && heap[i] > heap[i / 2]) {
        int temp = heap[i];
        heap[i] = heap[i / 2];
        heap[i / 2] = temp;
        i = i / 2;
    }
}

void display() {
    printf("Max Heap: ");
    for (int i = 1; i <= size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insert(10);
    insert(40);
    insert(30);
    insert(60);
    insert(20);
    display();
    return 0;
}
