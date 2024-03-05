#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

typedef enum {
        ADDITION,
        SUBTRACTION,
        MULTIPLICATION,
        DIVISION,
        MODULOS,
        EXPONENTIATION,
        VALUE,
        LEFT_PARENTHESIS,
        RIGHT_PARENTHESIS,
        PERIOD
} TOKEN_TYPE;

typedef struct {
        TOKEN_TYPE type;
        double val;
} TOKEN;

typedef struct {
        size_t top;
        TOKEN* arr;
} STACK;

#endif
