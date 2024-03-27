#ifndef ERROR_H
#define ERROR_H

typedef enum {
        SUCCESS,
        ERROR_ILLEGAL_INPUT,
        ERROR_CANNOT_DIVIDE_BY_ZERO,
} Error;

#define SUCCESS "SUCCESS"
#define FAILED "FAILED"

#define NUM_ERRORS 3
extern const char* error_codes[NUM_ERRORS];
#undef NUM_ERRORS

#endif
