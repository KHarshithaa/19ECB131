#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue structure for level order
struct Node* queue[100];
int front = -1, rear = -1;

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Enqueue
void enqueue(struct Node* root) {
    queue[++rear] = root;
}

// Dequeue
struct Node* dequeue() {
    return queue[++front];
}
