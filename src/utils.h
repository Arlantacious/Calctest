#ifndef UTILS_H
#define UTILS_H

#define ERR_ILLEGAL_INPUT "Error: Illegal input!"

struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
};

struct Stack {
    struct Node* top;
};

void push(struct Stack* stack, char ch);

char* pop(struct Stack* stack, unsigned int depth);

#endif
