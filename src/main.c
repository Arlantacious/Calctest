#include <stdio.h>
#include "lexer.h"

int main(int argc, char* argv[]) {
    Stack out;

    char err = lex(argv[0], &out);

    while (out.top != NULL) {
        Token* token = pop(&out, NULL);
        printf("VAL: %f SIG: %s", token->val, &token->sig);
    }

    printf("ERROR: %s", &err);
    
    return 0;
}
