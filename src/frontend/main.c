#include <stdio.h>
#include "../backend/arrange.h"
#include "../backend/utils.h"

int main(void) {
    Token t1;
    t1.val = 1;
    t1.id = VALUE;

    Token t2;
    t2.val = 0;
    t2.id = ADD;

    Token t3;
    t3.val = 2;
    t3.id = VALUE;

    Token t4;
    t4.val = 0;
    t4.id = SUBTRACT;

    Token t5;
    t5.val = 3;
    t5.id = VALUE;

    Token t6;
    t6.val = 0;
    t6.id = MULTIPLY;

    Token t7;
    t7.val = 4;
    t7.id = VALUE;

    Token t8;
    t8.val = 0;
    t8.id = DIVIDE;

    Token t9;
    t9.val = 5;
    t9.id = VALUE;

    Token end;
    end.val = 0;
    end.id = END;

    Token testin[] = { t1, t2, t3, t4, t5, t6, t7, t8, t9, end };
    char* errmsg = arrange(testin);

    fprintf(stderr, "exit: %s\n", errmsg);
    return 0;
}
