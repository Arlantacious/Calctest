#include "../headers/utils.h"

Error SUCCESS = { 0, "SUCCESS" };
Error ERROR_ILLEGAL_INPUT   = { 1, "ERROR_ILLEGAL_INPUT" };
Error ERROR_STACK_OVERFLOW   = { 2, "ERROR_STACK_OVERFLOW" };
Error ERROR_STACK_UNDERFLOW  = { 3, "ERROR_STACK_UNDERFLOW" };
Error ERROR_CANNOT_DIVIDE_BY_ZERO   = { 4, "ERROR_CANNOT_DIVIDE_BY_ZERO" };

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
