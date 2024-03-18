#include "calculator.h"
#include "parser.h"
#include "../utils/error.h"
#include "../utils/stack.h"

ERROR calculate(Token tokens) {
        Stack* ordered_tokens = stack();
        ERROR parse_err = parse(tokens, ordered_tokens);
        if (parse_err != SUCCESS) {
                return parse_err;
        }
        return SUCCESS;
}

