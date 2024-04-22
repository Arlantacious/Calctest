#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "arrange.h"
#include "utils.h"

char* geterrmsg[] = {
    [SUCCESS] = "success",
    [ERROR_ILLEGAL_INPUT] = "illegal input"
};

char* gettokenid[] = {
    [0] = "VALUE",
    [1] = "ADD",
    [2] = "SUBTRACT",
    [3] = "MULTIPLY",
    [4] = "DIVIDE",
    [5] = "END"
};

char* getopsymbol[] = {
    [1] = "+",
    [2] = "-",
    [3] = "*",
    [4] = "/",
};

int isprec(Token op1, Token op2) {
   if (op1.id == ADD || op1.id == SUBTRACT)
        if (op2.id == MULTIPLY || op2.id == DIVIDE)
            return 1;
   return 0;
}

char* arrange(Token in[]) {
    Error err = SUCCESS;
    Stack out;
    Stack ops;

    init_stack(&out);
    init_stack(&ops);

    for (Token* src = in; src->id != END; src++) {
        if (src->id == VALUE) {
            push(&out, *src);
            continue;
        }

        if (isempty(&ops) || !isprec(*src, ops.top->data)) {
            push(&ops, *src);
            continue;
        }

        while (!isempty(&ops) && isprec(ops.top->data, *src))
            push(&out, pop(&ops));
        
        push(&ops, *src);
    }

    while (!isempty(&ops))
        push(&out, pop(&ops));
      
     return geterrmsg[err];
 }
