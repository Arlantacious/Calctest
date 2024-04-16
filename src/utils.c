#include <stdlib.h>
#include "utils.h"

void push(Stack* src, Token data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->prev = src->top;
    src->top = node;
}

Token* pop(Stack* src, int depth) {
    if (depth == -1) {
        struct Node* tmp = src->top;
        src->top = src->top->prev;
        Token* data = &(tmp->data);
        free(tmp);
        return data;
    }

    struct Node* tmp = src->top;

    for (; depth > 0; depth--) {
        tmp = tmp->prev;
    }

    struct Node* next_node = tmp->prev;
    Token* data = &(tmp->data);

    if (next_node != NULL)
        next_node->next = tmp->next;

    free(tmp);
    return data;
}

void init_stack(Stack* stack) {
    stack->top = NULL;
}

void free_stack(Stack* stack) {
    struct Node* current = stack->top;

    while (current != NULL) {
        struct Node* next = current->prev;
        free(current);
        current = next;
    }

    stack->top = NULL;
}

