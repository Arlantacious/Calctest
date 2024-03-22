#ifndef QUEUE_H
#define QUEUE_H

#include "token.h"

typedef struct Queue_Node {
    Token token;
    struct Queue_Node* next;
} Queue_Node;

typedef struct {
    Queue_Node* front;
    Queue_Node* rear; 
} Queue;

Queue* queue(void);
void enqueue(Queue* queue, Token token);
Token dequeue(Queue* queue);
void merge(Queue* base_queue, Queue* queue);

#endif

