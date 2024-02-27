#ifndef UTILS_H
#define UTILS_H

typedef enum {
        ADDITION,
        SUBTRACTION,
        MULTIPLICATION,
        DIVISION,
        MODULOS,
        EXPONENTIATION,
} OPERATIONS;

struct stack {
        unsigned int top;
        void* arr;
};

#endif
