#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

typedef enum {
        END,
        VAL,
        ADD,
        SUB,
        MLT,
        DIV,
        MOD,
        EXP,
        LPN,
        RPN,
} TokenType;

typedef struct {
        int8_t code;
        char* litrl;
} Error;

typedef struct {
        size_t len;
        TokenType type;
        double val;
} Token;

typedef struct {
        size_t top;
        Token* arr;
} Stack;

extern Error SUCCESS;
extern Error ERROR_ILLEGAL_INPUT;
extern Error ERROR_STACK_OVERFLOW;
extern Error ERROR_STACK_UNDERFLOW;
extern Error ERROR_CANNOT_DIVIDE_BY_ZERO;

void push(Stack* stack, Token token);
void push_stack(Stack* base_stack, Stack* stack);
Token pop(Stack* stack);

#endif
