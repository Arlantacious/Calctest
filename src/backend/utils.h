#ifndef UTILS_H
#define UTILS_H


#define SUCCESS 0
#define ILLEGAL_IN 1


typedef struct {
    unsigned char success : 1;
    unsigned char operator_subceeds_operator : 1;
    unsigned char operand_subceeds_operand : 1;
    unsigned char unclosed_paren : 1;
    unsigned char subceeds_min_flt : 1;
    unsigned char exceeds_max_flt : 1;
} err;


#define FLOAT 0x01

#define IS_OPERAND(x) (x & FLT)


#define ADDITION        0x02
#define SUBTRACTION     0x03
#define MULTIPLICATION  0x04
#define DIVISION        0x05
#define MODULOS         0x06
#define EXPONENTIATION  0x07

#define IS_OPERATOR(x) (x & ADD || x & SUB || x & MUL || x & DIV || x & MODULOS || x & EXPONENTIATION )


typedef struct {
    float val;
    unsigned char id;
} token;


struct node {
    node* next;
    node* prev;
    token data;
};


typedef struct {
    struct Node* top;
} stack;


void init_stack(stack* stack);

void free_stack(stack* stack);

void push(stack* stack, token data);

token pop(stack* stack);

int isempty(stack* stack);

#endif
