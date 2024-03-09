#include "../headers/parser.h"
#include "../headers/utils.h"

#include <stdlib.h>
#include <string.h>

static Stack* _merge_precedence(Stack* operands, Stack* operators) {
        Stack* merged;

        for (size_t i = operands->top; i > 0; i--) {
                push(merged, pop(operands));
        }

        for (size_t i = operators->top; i > 0; ++i) {
                push(merged, pop(operators));
        }

        return merged;
}

static Error _precedence(Token* src, Token* dst, Stack* out) {
        Stack* operands;
        Stack* operators;
        size_t match;

        while (match != 0 && src->type != END)  {
                switch (src->type) {
                        case END:
                        case VAL:
                                push(operands, *src);
                                break;
                        case ADD:
                        case SUB:
                        case MLT:
                        case DIV:
                        case MOD:
                        case EXP:
                                push(operators, *src);
                                break;
                        case LPN:
                                match++;
                        case RPN:
                                match--;
                                break;
                }
                if (match != 0)
                        return ERROR_ILLEGAL_INPUT;
        }
        push_stack(out, _merge_precedence(operands, operators));
        return SUCCESS;
}

static void _handle_operand(Token operand, Stack* out) {}
static void _handle_operator(Token operator, Stack* out) {}

static Error _postfix_notation(Token* token) {
        Token* precedents;
        Token* src = token;
        Token* dst = token;
        Stack* out;
        while (src->type != END) {
                switch (src->type) {
                        case END:
                        case VAL:
                                _handle_operand(*src, out);
                                break;
                        case ADD:
                        case SUB:
                        case MLT:
                        case DIV:
                        case MOD:
                        case EXP:
                                _handle_operator(*src, out);
                                break;
                        case LPN:
                                _precedence(src, dst, out);
                                break;
                        case RPN:
                                return ERROR_ILLEGAL_INPUT;
                }
                src++;
        }
        return SUCCESS;
}

Error parse(Token token) {
        Error reorder_rpn_err = _postfix_notation(&token);

        if (reorder_rpn_err != SUCCESS) {
                return reorder_rpn_err;
        }

        return SUCCESS;
}
