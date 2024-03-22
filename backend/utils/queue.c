#include "queue.h"
#include "token.h"

Queue* queue(void) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}

void enqueue(Queue* queue, Token token) {
    Queue_Node* node = (Queue_Node*)malloc(sizeof(Queue_Node));
    node->token = token;
    node->next = NULL;

    if (queue->front == NULL) {
        queue->front = node;
        queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }

    free(node);
}

Token dequeue(Queue* queue) {
    Token token = queue->front->token;;
    Queue_Node* node = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(node);
    return token;
}

void merge(Queue* base_queue, Queue* queue) {
    for (Queue* queue; queue->front != NULL; enqueue(base_queue, dequeue(queue)));
}

void insert(Queue* base_queue, Queue queue, size_t depth) {
    Queue* temp;
    for (size_t depth; depth > 0; depth--) {
        enqueue(temp, dequeue(base_queue));
    }
    for (Queue* queue; queue->front != NULL; enqueue(base_queue, dequeue(queue)));
    for (Queue* temp; temp->front != NULL; enqueue(base_queue, dequeue(temp)));

    free(temp);
}
