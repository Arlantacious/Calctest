#include "lexer.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

static Error _try_val(char* init_c, double* val) {
    char strval;

    for (char* c = init_c; *c != '\n'; c++) {
        if (isdigit(*c)) {
            strcat(&strval, c);
            continue;
        } 
        if (*c == '.') {
            if (strchr(&strval, '.') == NULL) { 
                strcat(&strval, c);
                continue;
            } 

            return ERR_ILLEGAL_INPUT;
        }
    }
    *val = strtod(&strval, NULL);

    return SUCCESS;
}

static bool _isop(char* ch) {
    static char operators[] = { '+', '-', '*', '/' };

    if (strpbrk(ch, operators) != NULL)

        return true;
    
    return false;
}

Error lex(char str[], Stack* out) {
    Error err = SUCCESS;
    Token token;
    double val;
 
    for (char* ch = str; *ch != '\n'; ch++) {
        if (isdigit(*ch)) {
            _try_val(ch, &val);

            if (err != SUCCESS)

                return err; 

            token.val = val;
            push(out, token);
            continue;
        }

        if (_isop(ch)) {
            token.lit = *ch;
            push(out, token);
        }
    }

    return err;
}

