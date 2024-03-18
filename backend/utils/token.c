#include <stdbool.h>
#include "token.h"

inline TOKEN_TYPE which_type(const Token* token) {
        switch (token->type) {
                case TOKEN_VAL:
                       return TOKEN_TYPE_OPERAND;
                case TOKEN_ADD:
                case TOKEN_SUB:
                case TOKEN_MLT:
                case TOKEN_DIV:
                case TOKEN_MOD:
                case TOKEN_EXP:
                        return TOKEN_TYPE_OPERATOR;
                case TOKEN_LPN:
                case TOKEN_RPN:
                        return TOKEN_TYPE_SPECIAL;;

        }
}

