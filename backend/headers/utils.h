#ifndef UTILS_H
#define UTILS_H

typedef enum {
        DOUBLE,
        ADDITION,
        SUBTRACTION,
        MULTIPLICATION,
        DIVISION,
        MODULOS,
        EXPONENTIATION,
        LEFT_PARENTHESIS,
        RIGHT_PARENTHESIS,
} TOKEN_TYPE;

typedef struct {
        TOKEN_TYPE type;
        union {
                char* literl;
                double val;
        };
} TOKEN;

typedef struct {
        unsigned int top;
        TOKEN* arr;
} STACK;

#endif
