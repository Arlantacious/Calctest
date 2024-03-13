#include "error.h"

const char* error_codes[NUM_ERRORS] = {
        [SUCCESS] = "SUCCESS",
        [ERROR_ILLEGAL_INPUT] = "ERROR_ILLEGAL_INPUT",
        [ERROR_CANNOT_DIVIDE_BY_ZERO] = "ERROR_CANNOT_DIVIDE_BY_ZERO"
};

#undef NUM_ERRORS


