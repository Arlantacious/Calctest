#ifndef GLOBALS_H
#define GLOBALS_H

#define BUFFER_SIZE 99

typedef struct {
        unsigned int code;
        char* litrl;
} ERR;

extern ERR SUCCESS;
extern ERR ERROR_ILLEGAL_INPUT;
extern ERR ERROR_ILLEGAL_INPUT_EXCEEDS_BUFFER_LIMIT;
extern ERR ERROR_STACK_OVERFLOW;
extern ERR ERROR_STACK_UNDERFLOW;
extern ERR ERROR_CANNOT_DIVIDE_BY_ZERO;

#endif
