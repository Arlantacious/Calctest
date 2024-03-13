#include "calculator.h"
#include "parser.h"
#include "../utils/error.h"


ERROR calculate(Token tokens) {
        ERROR parse_err = parse(&tokens);
        if (parse_err != SUCCESS) {
                return parse_err;
        }
        return SUCCESS;
}

