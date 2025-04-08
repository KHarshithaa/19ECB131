#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Queue node for level order
struct Node** createQueue(int* front, int* rear) {
    struct Node** queue = (struct Node**) malloc(sizeof(struct Node*) * 100);
    *front = *rear = 0;
    return queue;
}

void enqueue(struct Node** queue, int* rear, struct Node* node) {
    queue[(*rear)++] = node;
}

struct Node* dequeue(struct Node** queue, int* front) {
    return queue[(*front)++];
}

void levelOrder(struct Node* root) {
    if (root == NULL) return;

    int front, rear;
    struct Node** queue = createQueue(&front, &rear);
    enqueue(queue, &rear, root);

    while (front < rear) {
        struct Node* temp = dequeue(queue*
