#include <stdio.h>
#include "lexer.h"

void debug(Stack out, Error err) {
    while (out.top != NULL) {
        Token* token = pop(&out, -1);
        printf("VAL: %f LIT: %s\n", token->val, &token->lit);
    }

    printf("ERROR: %d", err);

}

int main(int argc, char* argv[]) {
    
    if (argc == 2)
        return 1;

    Stack out;

    Error err = lex(argv[0], &out);
    debug(out, err);
    
    return 0;
}
