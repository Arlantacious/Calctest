#ifndef UTILS_H
#define UTILS_H

#define SUCCESS ""
#define ERR_ILLEGAL_INPUT "illegal input"

typedef struct {
    union {
        char sig;
        double val;
    };
} Token;

struct Node {
    struct Node* next;
    struct Node* prev;
    Token data;
};

typedef struct {
    struct Node* top;
} Stack;

void push(Stack* stack, Token data);

Token* pop(Stack* stack, unsigned int depth);

#endif
