#include "parser.h"
#include "../utils/stack.h"
#include "../utils/token.h"
#include <stdlib.h>
#include <string.h>

static ERROR _precedence(Token* src, Stack* dst) {
        Stack* operands; //Stack to temporarily store operand tokens.
        Stack* operators; //Stack to temporarily store operator tokens.
        size_t match; //Unsigned integer to store the difference in parenthesis matching.
        //Traverse through tokens until a match or return an error.
        for (Token* token = src; match != 0 && token != NULL; token++) {
                switch (src->type) {
                        case TOKEN_VAL:
                                push(operands, *src);
                                break;
                        case TOKEN_ADD:
                        case TOKEN_SUB:
                        case TOKEN_MLT:
                        case TOKEN_DIV:
                        case TOKEN_MOD:
                        case TOKEN_EXP:
                                push(operators, *src);
                                break;
                        case TOKEN_LPN:
                                match++;
                        case TOKEN_RPN:
                                match--;
                                break;
                }
                if (match != 0)
                        return ERROR_MISMATCHED_PARENTHESIS;
        }
        Stack* tokens = merge(operands, operators);
        merge(dst, tokens);
        return SUCCESS;
}

static inline ERROR _handle_operator(Token operator, Stack* dst) {
        static Stack operators;
        if (operators.top > 1) {
                return ERROR_ILLEGAL_INPUT;
        }
        push(&operators, operator);
        if (peek(dst, 2).type == TOKEN_VAL )
                push(dst, pop(&operators));

        return SUCCESS;

}

//1 2 + 3 4 * 56 / - 7 + 8 9 * 1011 / -
static ERROR _postfix_notation(Token* token) {
        Token* src = token; //Pointer to traverse through tokens. 
        Stack* dst; //Stack to store ordered tokens.
        for (Token* token = src; token != NULL; token++) {
                switch (token->type) {
                        case TOKEN_VAL:
                                push(dst, *token);
                                break;
                        case TOKEN_ADD:
                        case TOKEN_SUB:
                        case TOKEN_MLT:
                        case TOKEN_DIV:
                        case TOKEN_MOD:
                        case TOKEN_EXP:
                                _handle_operator(*token, dst);
                                break;
                        case TOKEN_LPN:
                                _precedence(token, dst);
                                break;
                        case TOKEN_RPN:
                                return ERROR_ILLEGAL_INPUT;
                }
                token++;
        }

        return SUCCESS;
}

ERROR parse(Token* token) {
        ERROR postfix_notation_err = _postfix_notation(token);
        if (postfix_notation_err != SUCCESS) {
                return postfix_notation_err;
        }

        return SUCCESS;
}
