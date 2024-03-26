#include "calculator.h"
#include "parser.h"
#include "../utils/error.h"
#include "../utils/stack.h"
#include <string.h>
#include "../utils/token.h"

//input: string
//-> traverse
//-> if operator push to operator stack + handle precedence (pop) and calculate
//-> if operand push to operand stack
//-> jump correct number of spaces for pointer 
//return top of stack

static void getval(char substr[]) {
    return NULL;
}

static char getop() {}

double  calculate(char str[], ERROR* err) { 
    for (char* ch = str; strcmp(ch, NULL); ch++) {
        
    }
}
