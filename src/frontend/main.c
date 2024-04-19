#include <stdio.h>
#include "../backend/arrange.h"
#include "../backend/utils.h"

int main(void) {
    Token t1;
    t1.val = 1;
    t1.id = VALUE;

    Token t2;
    t2.id = ADD;

    Token t3;
    t3.val = 2;
    t3.id = VALUE;

    Token t4;
    t4.id = SUBTRACT;

    Token t5;
    t5.val = 3;
    t5.id = VALUE;

    Token end;
    end.id = END;

    Token testin[] = { t1, t2, t3, t4, end };
    char* errmsg = arrange(testin);

    fprintf(stderr, "exit: %s", errmsg);
    return 0;
}
