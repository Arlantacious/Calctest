#include <stdlib.h>
#include "utils.h"

unsigned char flags;

int isempty(Stack* src) {
    if (src->top == NULL)
        return 1;
    return 0;
}

void push(Stack* src, Token data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->prev = src->top;
    src->top = node;
}

Token pop(Stack* src) {
    struct Node* tmp = src->top;
    src->top = src->top->prev;
    Token data = tmp->data;
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

