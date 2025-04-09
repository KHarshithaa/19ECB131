#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top < MAX - 1)
        stack[++top] = ch;
}

char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}

char peek() {
    if (top >= 0)
        return stack[top];
    return '\0';
}

int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int j = 0;

    for (int i = 0; infix[i]; i++) {
        char ch = infix[i];

        if (ch == ' ' || ch == '\n')
            continue;

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top >= 0 && peek() != '(')
                postfix[j++] = pop();
            pop(); // Remove '('
        } else if (isOperator(ch)) {
            while (top >= 0 && precedence(peek()) >= precedence(ch))
                postfix[j++] = pop();
            push(ch);
        }
    }

    while (top >= 0)
        postfix[j++] = pop();

    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
}

int main() {
    char expr[MAX];
    printf("Enter infix expression: ");
    fgets(expr, MAX, stdin);

    printf("Converting...\n");
    infixToPostfix(expr);

    return 0;
}
