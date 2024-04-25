#ifndef UTILS_H
#define UTILS_H


#include <stdlib.h>
#include <assert.h>


#define VALUE 0

#define ADD 1
#define SUBTRACTION 2
#define MULTIPLICATION 3
#define DIVISION 4
#define MODULUS 5
#define EXPONENTATION 6

#define TOKEN_EVALUATE_TYPE(a) ((a).type == (VALUE))

#define TOKEN_COMPARE_PRECEDENCE(a, b) (3)

struct token {
    float val;
    int type;
};

struct node {
    struct node* next;
    struct node* prev;
    struct token data;
};

struct stack {
    struct node* top;
};


#define SUCCESS 0

#define OPERATOR_FOLLOWED_BY_OPERATOR 1
#define OPERAND_FOLLOWED_BY_OPERAND 2
#define UNCLOSED_PARENTHESIS 3
#define LESS_THAN_MIN_FLOAT 4
#define GREATER_THAN_MAX_FLOAT 5


void stack_init(struct stack* stack);

void stack_push(struct stack* stack, struct token data);

struct token stack_pop(struct stack* stack);

int stack_is_empty(struct stack* stack);

void stack_free(struct stack* stack);


#endif
