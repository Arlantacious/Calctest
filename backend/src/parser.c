#include "../headers/parser.h"
#include "../headers/utils.h"
#include "../../globals/headers/globals.h"

#include <stdlib.h>
#include <string.h>

static void _convert_value(TOKEN* src, TOKEN* dst);

static ERR _init(TOKEN* src, TOKEN* dst) {
        switch (src->type) {
                case ADDITION:
                case SUBTRACTION:
                case MULTIPLICATION:
                case DIVISION:
                case MODULOS:
                case EXPONENTIATION:
                case LEFT_PARENTHESIS:
                case RIGHT_PARENTHESIS:
                        dst->type = src->type;
                        dst++;
                case VALUE:
                case PERIOD:
                        return ERROR_ILLEGAL_INPUT;
        }
        src++;
}

ERR parse(TOKEN token[BUFFER_SIZE]) {
        TOKEN* src = token;
        TOKEN* dst = token;

        ERR init_err = _init(src, dst);
        if (strcmp(init_err.litrl, "SUCCESS")) {
                return init_err;
        }

        return SUCCESS;
}
