#include "utils.h"


void stack_init(struct stack* s) {
    s->top = NULL;
}


void stack_push(struct stack* s, struct token data) {
    assert(s != NULL);
    struct node* node = malloc(sizeof(struct node));
    assert(node != NULL);
    node->data = data;
    node->prev = s->top;
    s->top = node;
}


struct token stack_pop(struct stack* s) {
    assert(s != NULL);
    struct token data = s->top->data;
    s->top = s->top->prev;
    return data;
}


int stack_is_empty(struct stack* s) {
    assert(s != NULL);
    return s->top == NULL;
}


void stack_free(struct stack* s) {
    while (s->top != NULL) {
        struct node* next = s->top->prev;
        free(s->top);
        s->top = next;
    }

    assert(s->top == NULL);
}
