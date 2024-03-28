#include <stdlib.h>
#include "utils.h"

void push(struct Stack* stack, char ch) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = ch;
    stack->top = node;
}

char* pop(struct Stack* stack, unsigned int depth) {
    struct Node* tmp = stack->top;
    for (size_t depth; depth > 0; depth--) {
        tmp = tmp->prev;
    }
    char data = tmp->data;
    stack->top = tmp->next;
    free(tmp);
    return &data;
}


