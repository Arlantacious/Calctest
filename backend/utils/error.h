#ifndef ERROR_H
#define ERROR_H

typedef enum {
        SUCCESS,
        ERROR_ILLEGAL_INPUT,
        ERROR_MISMATCHED_PARENTHESIS,
        ERROR_CANNOT_DIVIDE_BY_ZERO,
} ERROR;

#define NUM_ERRORS 4
extern const char* error_codes[NUM_ERRORS];

#endif
