#include <stdlib.h>
#include <string.h>
#include "utils.h"

void push(Stack* stack, Token data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    stack->top = node;
}

Token* pop(Stack* stack, int init_depth) {
    if (init_depth == -1) {
        stack->top = stack->top->prev;
        return &stack->top->data;
    }

    struct Node* tmp = stack->top;

    for (int depth = init_depth; depth > 0; depth--) {
        tmp = tmp->prev;
    }

    Token* data = &tmp->data;
    stack->top = tmp->next;
    free(tmp);
    return data;
}


