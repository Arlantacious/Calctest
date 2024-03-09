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
        size_t len;
        TokenType type;
        double val;
} Token;

typedef struct {
        size_t top;
        Token* arr;
} Stack;


void push(Stack* stack, Token token);
void push_stack(Stack* base_stack, Stack* stack);
Token pop(Stack* stack);

typedef enum {
        SUCCESS,
        ERROR_ILLEGAL_INPUT,
        ERROR_CANNOT_DIVIDE_BY_ZERO,
} Error;

static const char* error_code[] = {
        [SUCCESS] = "SUCCESS",
        [ERROR_ILLEGAL_INPUT] = "ERROR_ILLEGAL_INPUT",
        [ERROR_CANNOT_DIVIDE_BY_ZERO] = "ERROR_CANNOT_DIVIDE_BY_ZERO"
};


#endif
