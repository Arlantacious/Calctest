#include <stdlib.h>
#include <string.h>
#include "utils.h"

void push(Stack* src, Token data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    src->top = node;
}

Token* pop(Stack* src, int depth) {
    if (depth == -1) {
        src->top = src->top->prev;

        return &src->top->data;
    }

    struct Node tmp = *src->top;

    for (; depth > 0; depth--) {
        tmp = *tmp.prev;
    }

    Token* data = &tmp.data;
    src->top = tmp.next;

    return data;
}


