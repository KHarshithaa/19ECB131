#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Stack structure
char stack[MAX];
int top = -1;

// Queue structure
char queue[MAX];
int front = 0, rear = -1;

// Push to stack
void push(char ch) {
    if (top < MAX - 1)
        stack[++top] = ch;
}

// Pop from stack
char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}

// Enqueue to queue
void enqueue(char ch) {
    if (rear < MAX - 1)
        queue[++rear] = ch;
}

// Dequeue from queue
char dequeue() {
    if (front <= rear)
        return queue[front++];
    return '\0';
}

int isPalindrome(char str[]) {
    int len = strlen(str);

    // Reset globals
    top = -1;
    front = 0;
    rear = -1;

    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            push(str[i]);
            enqueue(str[i]);
        }
    }

    for (int i = 0; i < len / 2; i++) {
        if (pop() != dequeue())
            return 0;
    }

    return 1;
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    // Convert to lowercase for uniform check
    for (int i = 0; str[i]; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;

    if (isPalindrome(str))
        printf("✅ It is a palindrome!\n");
    else
        printf("❌ Not a palindrome.\n");

    return 0;
}
