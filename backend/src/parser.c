#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "../utils/stack.h"
#include "../utils/queue.h"
#include "../utils/token.h"
/*
 * @param src: raw token array input
 * @param out: processed tokens output
 * @param err: error code
 */
static void _precedence(Token* src, Stack* out, ERROR* err) {
    Queue* operands = queue();
    Queue* operators = queue();
    unsigned int match;
    for (Token* token = src; token != NULL; token++) {
        switch (token->kind) {
            case TOKEN_KIND_OPERAND:
                enqueue(operands, *token);
                break;
            case TOKEN_KIND_OPERATOR:
                enqueue(operators, *token);
                break;
            case TOKEN_KIND_SPECIAL:
                if (token->name == TOKEN_LPN) {
                    match++;
                } else {
                    match--;
                }
        }
        if (match == 0)
            break;
    }
    Queue* segment;
    merge(segment, operands);
    merge(segment, operators);

    *err = SUCCESS;
}
/*
 * @param src: raw token array input
 * @param out: processed tokens output
 * @param err: error code
 * @return: output stack
 */
static Stack* _rpn(Token* src, ERROR* err) {
    Stack* out = stack();
    Queue* operators = queue();
    for (Token* token = src; token != NULL; token++) {
        if (token->kind  == TOKEN_KIND_OPERAND) {
            push(out, *token);
        } else if (token->kind == TOKEN_KIND_OPERATOR) {
            enqueue(operators, *token);
            push(out, dequeue(operators));
        } else if (token->name == TOKEN_LPN) {
            _precedence(token, out, err);
        } else if (token->name == TOKEN_RPN) {
            *err =  ERROR_MISMATCHED_PARENTHESIS;
        } 
    }

    free(operators);
    *err =  SUCCESS;
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
