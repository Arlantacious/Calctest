#ifndef UTILS_H
#define UTILS_H

#define BUF_SIZE 64

typedef enum {
    SUCCESS = 0,
    ERR_ILLEGAL_INPUT = 1
} Error;

typedef struct {
    union {
        char op;
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

Token* pop(Stack* stack, int depth);

#endif
