#ifndef STACK_H
#define STACK_H

#include "token.h"

typedef struct Stack_Node {
    Token token;
    struct Stack_Node* next;
} Stack_Node;

typedef struct {
    Stack_Node* top; 
} Stack;

Stack* stack(void);
void push(Stack* stack, const Token token);
Token pop(Stack* stack);
Token peek(const Stack* stack);

#endif
