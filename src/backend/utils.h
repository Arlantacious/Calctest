#ifndef UTILS_H
#define UTILS_H


#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <assert.h>


typedef enum
{
        END = -1,
        VAL = 0,
        ADD = 1,
        SUB = 2,
        MUL = 3,
        DIV = 4,
        MOD = 5,
        EXP = 6
} Token_ID;

typedef enum
{
        OP_FOLLOWED_BY_OP = -4,
        VAL_FOLLOWED_BY_VAL = -3,
        VAL_EXCEEDS_LIMIT = -2,
        UNCLOSED_PAREN = -1,
        SUCCESS = 0,
        SAFE_FAIL = 1
} Exit_Code;


typedef struct
{
    float val;
    Token_ID id;
    int prec;
} Token;

struct Node
{
    struct Node* next;
    struct Node* prev;
    Token data;
};

typedef struct
{
    struct Node* top;
} Stack;


int token_eval_id(Token_ID id);

int token_cmp_prec(Token_ID stack_id, Token_ID current_id);

void stack_init(Stack* stack);

void stack_push(Stack* stack, Token data);

Token stack_pop(Stack* stack);

void stack_reverse(Stack* stack);

int stack_is_empty(Stack* stack);

void stack_free(Stack* stack);

void debug_print_stack(Stack stack);


#endif
