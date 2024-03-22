#include "stack.h"

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;

    return stack;
}

void push(Stack* stack, Token token) {
    Stack_Node* node = (Stack_Node*)malloc(sizeof(Stack_Node));
    node->token = token;
    node->next = stack->top;
    stack->top = node;

    free(node);
}

Token pop(Stack* stack) {
    Token token = stack->top->token;
    Stack_Node* temp = stack->top;
    stack->top = stack->top->next;

    free(temp);
    return token;
}

Token peek(const Stack* stack) {
    return stack->top->token;;
}
