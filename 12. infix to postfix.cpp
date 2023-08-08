#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100
struct Stack {
    int top;
    char items[MAX_SIZE];
};

void push(struct Stack *stack, char value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack is full. Cannot push.\n");
    } else {
        stack->top++;
        stack->items[stack->top] = value;
    }
}

char pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty. Cannot pop.\n");
        return '\0';
    } else {
        char value = stack->items[stack->top];
        stack->top--;
        return value;
    }
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    struct Stack operatorStack;
    operatorStack.top = -1;
    int postfixIndex = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[postfixIndex++] = infix[i];
        } else if (infix[i] == '(') {
            push(&operatorStack, '(');
        } else if (infix[i] == ')') {
            while (operatorStack.top != -1 && operatorStack.items[operatorStack.top] != '(') {
                postfix[postfixIndex++] = pop(&operatorStack);
            }
            pop(&operatorStack); 
        } else { 
            while (operatorStack.top != -1 && precedence(infix[i]) <= precedence(operatorStack.items[operatorStack.top])) {
                postfix[postfixIndex++] = pop(&operatorStack);
            }
            push(&operatorStack, infix[i]);
        }
    }
    while (operatorStack.top != -1) {
        postfix[postfixIndex++] = pop(&operatorStack);
    }
    postfix[postfixIndex] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
