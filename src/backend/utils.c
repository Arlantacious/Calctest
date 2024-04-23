#include <stdlib.h>
#include <assert.h>
#include "utils.h"


void init_stack(struct stack* s) {
    s->top = NULL;
}


void push(struct stack* s, struct token data) {
    assert(s != NULL);
    struct node* node = malloc(sizeof(struct node));
    assert(node != NULL);
    node->data = data;
    node->prev = s->top;
    s->top = node;
}


struct token pop(struct stack* s) {
    assert(s != NULL);
    struct token data = s->top->data;
    s->top = s->top->prev;
    return data;
}


int isempty(struct stack* s) {
    assert(s != NULL);
    return s->top == NULL;
}


void free_stack(struct stack* s) {
    while (s->top != NULL) {
        struct node* next = s->top->prev;
        free(s->top);
        s->top = next;
    }

    assert(s->top == NULL);
}
