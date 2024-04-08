#include "lexer.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include "calculator.h"

static void _try_val(char* ch, double* val,  char* err) {
    char strval;

    for (char* ch = ch; *ch != '\n'; ch++) {
        if (isdigit(*ch)) {
            strcat(&strval, ch);
            continue;
        } 
        if (*ch == '.') {
            if (strchr(&strval, '.') == NULL) { 
                strcat(&strval, ch);
                continue;
            } 
            err = ERR_ILLEGAL_INPUT;

            return;
        }
    }
    *val = strtod(&strval, NULL);
}

char lex(char str[], Stack* out) {
    char* err = SUCCESS;
    Token token;
    double val;
    char signature;
 
    for (char* ch = str; *ch != '\n'; ch++) {
        if (isdigit(*ch)) {
            _try_val(ch, &val, err);
            if (err != NULL)

                return *err; 
            token.val = val;
            push(out, token);
            continue;
        }
    }

    return *err;
}

