#ifndef UTILS_H
#define UTILS_H


#define FLT 0x01

#define IS_OPERAND(x) (x & FLT)


#define ADD 0x02
#define SUB 0x04
#define MUL 0x08
#define DIV 0x10
#define MOD 0x20
#define EXP 0x40

#define IS_OPERATOR(x) (x & ADD || x & SUB || x & MUL || x & DIV || x & MOD || x & EXP )


typedef struct {
    unsigned success : 1;
    unsigned operator_subceeds_operator : 1;
    unsigned operand_subceeds_operand : 1;
    unsigned unclosed_paren : 1;
    unsigned subceeds_min_flt : 1;
    unsigned exceeds_max_flt : 1;
} err;


struct token {
    float val;
    unsigned char id;
};


struct node {
    struct node* next;
    struct node* prev;
    struct token data;
};


struct stack {
    struct node* top;
};


void s_init(struct stack* stack);

void s_push(struct stack* stack, struct token data);

struct token s_pop(struct stack* stack);

int s_isempty(struct stack* stack);

void s_free(struct stack* stack);

#endif
