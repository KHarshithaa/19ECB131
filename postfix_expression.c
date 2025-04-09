#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top < MAX - 1)
        stack[++top] = val;
}

int pop() {
    if (top >= 0)
        return stack[top--];
    return -1;
}

int evaluatePostfix(char* expr) {
    for (int i = 0; expr[i]; i++) {
        if (expr[i] == ' ' || expr[i] == '\n')
            continue;

        if (isdigit(expr[i])) {
            push(expr[i] - '0');
        } else {
            int val2 = pop();
            int val1 = pop();
            switch (expr[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return pop();
}

int main() {
    char expr[MAX];
    printf("Enter postfix expression (e.g., 23*54*+9-): ");
    fgets(expr, MAX, stdin);

    printf("Result = %d\n", evaluatePostfix(expr));
    return 0;
}
