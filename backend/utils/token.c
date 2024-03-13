#include <stdbool.h>
#include "token.h"

inline bool is_operand(const Token* token) {
        switch (token->type) {
                case TOKEN_ADD:
                case TOKEN_SUB:
                case TOKEN_MLT:
                case TOKEN_DIV:
                case TOKEN_MOD:
                case TOKEN_EXP:
                case TOKEN_LPN:
                case TOKEN_RPN:
                        return false;
                case TOKEN_VAL:
                        return true;
        }
}

inline bool is_operator_token(const Token* token) {
        switch (token->type) {
                case TOKEN_ADD:
                case TOKEN_SUB:
                case TOKEN_MLT:
                case TOKEN_DIV:
                case TOKEN_MOD:
                case TOKEN_EXP:
                        return true;
                case TOKEN_LPN:
                case TOKEN_RPN:
                case TOKEN_VAL:
                        return false;
        }
}
