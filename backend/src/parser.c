#include "../utils/stack.h"
#include "../utils/token.h"
#include "parser.h"
#include <stdlib.h>
#include <string.h>
/*
 * @params src: raw token array input
 * @param out: processed tokens output
 * @param err: error code
 * @return void
 */
static void _precedence(Token* src, Stack* out, ERROR* err) {
        Stack* operands;
        Stack* operators;
        unsigned int match;
        for (Token* src; match > 0 && src != NULL; src++) {
                if (is_operand(src)) {
                        push(operands, *src);
                } else if (is_operator(src)) {
                        push(operators, *src);
                } else if (src->type == TOKEN_LPN) {
                        match++;
                } else if (src->type == TOKEN_RPN) {
                        match--;
                }
        }
        if (match > 0)
                *err = ERROR_MISMATCHED_PARENTHESIS;
        Stack* tokens = merge(operands, operators);
        merge(out, tokens);
        *err = SUCCESS;
}

static ERROR _rpn(Token* src, Stack* out, ERROR* err) {
        Stack* operators = stack();
        for (Token* src; src != NULL; src++) {
                if (is_operand(src)) {
                        push(out, *src);
                } else if (is_operator(src)) {
                        push(operators, *src);
                } else if (src->type == TOKEN_LPN) {
                        _precedence(src, out, err);
                } else if (src->type == TOKEN_RPN) {
                        return ERROR_MISMATCHED_PARENTHESIS;
                }
        }
        free(operators);
        return SUCCESS;
}

/*
 * @param src: raw token array input
 * @param out: processed tokens output
 * @return ERROR: error code
 */
ERROR parse(Token src, Stack* out) {
        ERROR err;
        _rpn(&src, out, &err);
        if (err != SUCCESS) {
                return err;
        }
        return SUCCESS;
}
