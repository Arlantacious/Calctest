#include "../headers/utils.h"

void push(Stack* stack, const Token token) {
        stack->arr[stack->top++] = token;
}

void push_stack(Stack* base_stack, Stack* stack) {
        Token tokens[stack->top++];
        tokens[stack->top++].type = END;

        for (size_t i = stack->top; i > 0; i--)
             tokens[i] = pop(stack);

        for (Token* token = tokens; token->type != END; token++)
             base_stack->arr[stack->top++] = *token;
}
Token pop(Stack* stack) {
        return stack->arr[--stack->top];
}
