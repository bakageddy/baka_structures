#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int top;
    unsigned cap;
    int *array;
} Stack;

Stack *new(unsigned cap) {
    Stack *x = malloc(sizeof(Stack));
    if (!x) return NULL;
    x -> top = -1;
    x -> cap = cap;
    x -> array = malloc(sizeof(int) * cap);
    if (!x -> array) return NULL;
    return x;
}

int isEmpty(Stack *s) {
    return s -> top == -1;
}

char peek(Stack *s) {
    return s -> array[s -> top];
}

char pop(Stack *s) {
    if (!isEmpty(s)) return s -> array[s -> top--];
    return '$';
}

void push(Stack *stack, char elem) {
    stack -> array[++stack->top] = elem;
}

int isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int prec(char c) {
    if (c == '+' || c == '-') return 1;
    else if (c == '*' || c == '/') return 2;
    else if (c == '^') return 3;
    return -1;
}

int postfix(char *exp) {
    int i, k;
    Stack* stack = new(strlen(exp));
    if (!stack) return -1;
    for (i = 0, k = -1; exp[i]; ++i) {
        if (isOperand(exp[i])) exp[++k] = exp[i];
        else if (exp[i] == '(') push(stack, exp[i]);
        else if (exp[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return -1;
            else pop(stack);
        }
        else {
            while (!isEmpty(stack) && prec(exp[i]) <= prec(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }
    }
    while (!isEmpty(stack)) exp[++k] = pop(stack);
    exp[++k] = '\0';
    printf("%s\n", exp);
    return 0;
}

int main() {
    char exp[200];
    printf("Enter expression: ");
    scanf("%s", exp);
    postfix(exp);
    return 0;
}
