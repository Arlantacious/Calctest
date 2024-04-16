#include "lexer.h"

#define TEST_INPUT "1+2-3*4/5"

int main(void) {
    Stack out;
    ERROR err = lex(TEST_INPUT, &out);
    return err;
}
