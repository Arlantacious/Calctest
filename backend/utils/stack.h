#ifndef STACK_H
#define STACK_H

#include "token.h"

typedef struct {
        Token* tokens;
        int top;
} Stack;

Stack* stack(void);
void push(Stack* stack, const Token token);
Token pop(Stack* stack);
Token peek(const Stack* stack, const size_t depth);
Stack* merge(Stack* base_stack, Stack* stack);

#endif
