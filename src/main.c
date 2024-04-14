#include <stdio.h>
#include <math.h>
#include "lexer.h"

static const char* debug_err[] = {
    [SUCCESS] = "SUCCESS",
    [ERR_ILLEGAL_INPUT] = "ERR_ILLEGAL_INPUT"
};

void debug(char out[], Error err) {
    if (err == ERR_ILLEGAL_INPUT) {
        printf("ERR: %s\n", debug_err[err]);

        return;
    }

    printf("%s", out); 
}

int main(void) {
    char str[] = "1+2-3*4/5";
    char out;

    Error err = lex(str, &out);
 
    debug(&out, err);
    
    return 0;
}
