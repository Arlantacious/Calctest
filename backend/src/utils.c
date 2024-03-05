#include "../headers/utils.h"

void push(STACK* stack, TOKEN token) {
        stack->arr[stack->top++] = token;
}

TOKEN pop(STACK* stack) {
        return stack->arr[--stack->top];
}
