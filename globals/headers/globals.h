#ifndef GLOBALS_H
#define GLOBALS_H

#define INPUT_BUFFER_SIZE 99
#define NUM_OPERATIONS

typedef struct {
        unsigned int code;
        char* litrl;
} err;

extern err SUCCESS;
extern err ERROR_ILLEGAL_INPUT;
extern err ERROR_ILLEGAL_INPUT_EXCEEDS_BUFFER_LIMIT;
extern err ERROR_STACK_OVERFLOW;
extern err ERROR_STACK_UNDERFLOW;
extern err ERROR_CANNOT_DIVIDE_BY_ZERO;

#endif
