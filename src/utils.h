#ifndef UTILS_H
#define UTILS_H

#define BUF_SIZE 64

typedef enum {
    SUCCESS = 0,
    ERROR_ILLEGAL_INPUT = 1
} ERROR;

typedef struct {
    float val;
    char lit;
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
