#include <iostream>
#include <math.h>
#include "../backend/calculator.h"

int main(void) {
    Token t1;
    t1.val = 1;
    t1.id = VALUE;
    Token t2;
    t2.val = NAN;
    t2.id = ADD;
    Token t3;
    t3.val = 2;
    t3.id = VALUE;
    Token t4;
    t4.val = NAN;
    t4.id = SUBTRACT;
    Token t5;
    t5.val = 3;
    t5.id = VALUE;
    Token testin[] = { t1, t2, t3, t4 };
    size_t size = 4;
    char* errmsg = calculate(testin, size);

    std::cout << "%s" << errmsg;
    return 0;
}
