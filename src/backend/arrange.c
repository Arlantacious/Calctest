#include "arrange.h"

int arrange(struct token in[]) {
    int err = SUCCESS;
    struct stack out;
    struct stack ops;

    stack_init(&out);
    stack_init(&ops);

    for (struct token* src = in; src != NULL; src++) {
        if (TOKEN_EVALUATE_TYPE(*src)) {
            stack_push(&out, *src);
            continue;
        }

        if (stack_is_empty(&ops) || !TOKEN_COMPARE_PRECEDENCE(*src, ops.top->data)) {
            stack_push(&ops, *src);
            continue;
        }

        while (~stack_is_empty(&ops) & TOKEN_COMPARE_PRECEDENCE(ops.top->data, *src))
            stack_push(&out, stack_pop(&ops));
        
        stack_push(&ops, *src);
    }

    while (!stack_is_empty(&ops))
        stack_push(&out, stack_pop(&ops));
      
     return err;
 }
