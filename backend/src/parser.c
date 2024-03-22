#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "../utils/stack.h"
#include "../utils/queue.h"
#include "../utils/token.h"

static Token _precedence(Queue operators) {}

static Stack* _rpn(Token* src, ERROR* err) {
    Stack* out = stack();
    Queue* operators = queue();
    for (Token* token = src; token != NULL; token++) {
      
        if (token->kind  == TOKEN_KIND_OPERAND) {
            push(out, *token);
        } else {
            enqueue(operators, *token);
            push(out, dequeue(operators));
        } 
    }

    free(operators);
    return out;
}
/*
 * @param src: raw token array input
 * @param out: processed tokens output
 * @return ERROR: error code
 */
Stack* parse(Token src, ERROR* err) {

    Stack* out = _rpn(&src, err);

    if (err != SUCCESS) {   
        return out;;
    }

    return out;
}
