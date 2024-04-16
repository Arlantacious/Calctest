#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lexer.h"
#include "utils.h"

static char* isop(char c) {
    static char ops[] = "+-*/";
    size_t n = strlen(ops);
    char* match = memchr(ops, c, n);
 
    return match;
}

static char* isflt(char* str, ERROR* err) {
    _Bool period = 0;
    size_t len = 0;
    
    for (; isop(*str) != NULL; len++, str++) {
        if (*str == '.') {
            if (period) {
                *err = ERROR_ILLEGAL_INPUT;

                return NULL;
            }

            period = 1;
        }
    }

    char substr[len + 1];
    strncpy(substr, str - len, len);
    substr[len] = '\0';

    return strdup(substr);
}

ERROR lex(char str[], Stack* out) {
    ERROR err = SUCCESS;
    Stack tmp;

    for (; *str; str++) {
        if (*str == '.')

            return ERROR_ILLEGAL_INPUT;
       
        char* c = isop(*str);

        if (c != NULL) {
            Token data = { .lit = *c };
            push(&tmp, data);
        }

        if (isdigit(*str)) {
            char* strflt  = isflt(str, &err);
           
            if (strflt == NULL)
            
                return err;

            Token data = { .val = atof(strflt) };
            push(&tmp, data);
            free(strflt);
        }
    }
    
    *out = tmp;

    return err;
}
