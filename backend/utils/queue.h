#ifndef QUEUE_H
#define QUEUE_H

#include "token.h"

typedef struct {
        Token* tokens;
        int front;
        int rear;
        size_t size;
} Queue;

Queue* queue(void);

#endif
