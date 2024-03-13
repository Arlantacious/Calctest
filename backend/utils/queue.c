#include "queue.h"

Queue* queue(void) {
        Queue* queue = (Queue*)malloc(sizeof(Queue));
        queue->tokens = NULL;
        queue->front = -1;
        queue->rear = -1;
        queue->size = 0;
        return queue;
}

void enqueue(Queue* queue, const Token token) {
        if (queue->tokens == NULL) {
                queue->tokens = (Token*)malloc(sizeof(Token));
                queue->front = 0;
                queue->rear = 0;
        } else {
                queue->tokens = (Token*)realloc(queue->tokens, (queue->size + 1) * sizeof(Token));
                queue->rear = (queue->rear + 1) % (queue->size + 1);
        }
        queue->tokens[queue->rear] = token;
        queue->size++;
}

Token dequeue(Queue* queue) {
        Token removed_token = queue->tokens[queue->front];
        if (queue->front == queue->rear) {
                free(queue->tokens);
                queue->tokens = NULL;
                queue->front = -1;
                queue->rear = -1;
        } else {
                queue->front = (queue->front + 1) % queue->size;
        }
        queue->size--;
        return removed_token;
}
