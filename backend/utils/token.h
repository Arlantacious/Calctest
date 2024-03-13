#ifndef TOKEN_H
#define TOKEN_H

#include <stdlib.h>

typedef enum {
        TOKEN_ADD,
        TOKEN_SUB,
        TOKEN_MLT,
        TOKEN_DIV,
        TOKEN_MOD,
        TOKEN_EXP,
        TOKEN_LPN,
        TOKEN_RPN,
        TOKEN_VAL,
} TOKEN_NAME;

typedef struct {
        TOKEN_NAME type;
        double val;
        size_t len;
} Token;

#endif
