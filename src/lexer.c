#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lexer.h"
#include "utils.h"

static char* isop(char c) {
    static char ops[] = "+-*/";
    char* match = memchr(ops, c, strlen(ops));
    return match;
}

static char* isflt(char* str, ERROR* err) {
    _Bool period = 0;
    size_t len = 0;
    
    while ((isdigit(*str) || *str == '.') && !period) {
        if (*str == '.') {
            if (period) {
                *err = ERROR_ILLEGAL_INPUT;
                return NULL;
            }

            period = 1;
        }
        len++;
        str++;
    }
    
    return str - len;
}

ERROR lex(char str[], Stack* out) {
    ERROR err = SUCCESS;
    Stack tmp;
    init_stack(&tmp);

    for (; *str; str++) {
        if (*str == '.')
            return ERROR_ILLEGAL_INPUT;
       
        char* c = isop(*str);

        if (c != NULL) {
            Token data = { .lit = *c };
            push(&tmp, data);
        }

        if (isdigit(*str)) {
            char* strflt = isflt(str, &err);
    
            if (strflt == NULL) {
                free_stack(&tmp);
                return err;
            }

            Token data = { .val = atof(strflt) };
            push(&tmp, data);
        }
    }
    
    *out = tmp;
    return err;
}
