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
} TOKEN_NAME;

typedef enum {
        TOKEN_KIND_OPERAND,
        TOKEN_KIND_OPERATOR,
} TOKEN_KIND;

typedef enum {
    TOKEN_PREC_HIGH,
    TOKEN_PREC_LOW
} TOKEN_PREC
;
typedef struct {
        TOKEN_NAME name;
        TOKEN_KIND kind;
        TOKEN_PREC prec;
        double val;
} Token;

#endif
