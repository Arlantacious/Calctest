#ifndef TOKEN_H
#define TOKEN_H

#include <stdlib.h>
#include <stdbool.h>

typedef enum {
        TOKEN_VAL,
        TOKEN_ADD,
        TOKEN_SUB,
        TOKEN_MLT,
        TOKEN_DIV,
        TOKEN_MOD,
        TOKEN_EXP,
        TOKEN_LPN,
        TOKEN_RPN,
} TOKEN_NAME;

typedef enum {
        TOKEN_TYPE_OPERAND,
        TOKEN_TYPE_OPERATOR,
        TOKEN_TYPE_SPECIAL
} TOKEN_TYPE;

typedef struct {
        TOKEN_NAME type;
        double val;
        size_t len;
} Token;

extern TOKEN_TYPE which_type(const Token* token);

#endif
