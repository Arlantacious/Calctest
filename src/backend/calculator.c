#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calculator.h"
#include "utils.h"

char* geterrmsg[] = {
    [SUCCESS] = "success",
    [ERROR_ILLEGAL_INPUT] = "illegal input"
};

int isprec(Stack* ops, Token in) {
   if (in.id == ADD || in.id == SUBTRACT)
        if (ops->top->data.id == MULTIPLY || ops->top->data.id == DIVIDE)
            return 1;
   return 0;
}

Error rearrange(Token* src, Stack* out, size_t size) {
    Stack ops;
    init_stack(&ops);

    for (size_t i = 0; i < size; i++) {
        if (src->id == VALUE) {
            push(out, *src);
            continue;
        }

        if (isempty(&ops) || !isprec(&ops, *src)) {
            push(&ops, *src);
            continue;
        }

        while (!isempty(&ops) && isprec(&ops, *src)) {
            push(out, pop(&ops, 0));
        }

        src++;
    }
    return SUCCESS;
}

char* calculate(Token src[], size_t size) {
    Error err = SUCCESS;
    Stack out;
    init_stack(&out);

    if (rearrange(src, &out, size) != SUCCESS)
        return geterrmsg[err];
    
    for (struct Node* current = out.top; current->prev != NULL; current = current->prev) {
        if (current->data.val == NAN) {
            printf("val: NAN");
        } else {
            printf("val: %f\n", current->data.val);
        }

        printf("id: %d\n\n", current->data.id);
    }

    return geterrmsg[err];
}
