#include "stack.h"

Stack* stack(void) {
        Stack* stack = (Stack*)malloc(sizeof(Stack));
        stack->tokens = NULL;
        stack->top = -1;
        return stack;
}

void push(Stack* stack, const Token token) {
        if (stack->tokens == NULL) {
                stack->tokens = (Token*)malloc(sizeof(Token));
        } else {
                stack->tokens = (Token*)realloc(stack->tokens, (++stack->top) * sizeof(Token));
        }
        stack->tokens[stack->top] = token;
}

Token pop(Stack* stack) {
        Token popped_token = stack->tokens[stack->top];
        if (stack->top == -1) {
                free(stack->tokens);
        } else {
                stack->tokens = (Token*)realloc(stack->tokens, (--stack->top) * sizeof(Token));
        }
        return popped_token;
}

Token peek(const Stack* stack, const size_t depth) {
        return stack->tokens[stack->top - depth];
}

Stack* merge(Stack* base_stack, Stack* stack) {
        Stack* new_stack = base_stack;
        for (size_t depth = stack->top; depth > 0; depth--) {
                push(new_stack, stack->tokens[depth]);
        }
        return new_stack;
}
