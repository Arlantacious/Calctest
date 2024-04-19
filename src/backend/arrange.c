#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arrange.h"
#include "utils.h"

char* geterrmsg[] = {
    [SUCCESS] = "success",
    [ERROR_ILLEGAL_INPUT] = "illegal input"
};

int isprec(Token op1, Token op2) {
   if (op1.id == ADD || op1.id == SUBTRACT)
        if (op2.id == MULTIPLY || op2.id == DIVIDE)
            return 1;
   return 0;
}

char* arrange(Token src[]) {
    Error err = SUCCESS;
    Stack out;
    Stack ops;

    init_stack(&out);
    init_stack(&ops);

    for (; src->id != END; src++) {
        if (src->id == VALUE) {
            push(&out, *src);
            continue;
        }

        if (isempty(&ops) || !isprec(ops.top->data, *src)) {
            push(&ops, *src);
            continue;
        }

        while (!isempty(&ops))
            push(&out, pop(&ops, 0));
        
        push(&ops, *src);
    }

    assert(src->id == END);
    
    for (struct Node* current = out.top; current != NULL; current = current->prev) {
        if (current->data.id == VALUE) {
            printf("val: %f\n", current->data.val);
            continue;
        }

        printf("id: %d\n\n", current->data.id);
    }

    return geterrmsg[err];
}
