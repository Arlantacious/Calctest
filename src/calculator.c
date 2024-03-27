#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "calculator.h"
#include "utils.h"
/* @param ch: current char in str
 * @param out: operands stack
 * @param err: error message
*/
static float _flt(char* ch, struct Stack* out, char* err) {
    char fltstr;

    for (char* ch; *ch != '\n'; ch++) {
        if (isdigit(*ch)) {
            strcat(&fltstr, ch);
            continue;
        } 
        if (*ch == '.') {
            if (strchr(&fltstr, '.') == NULL) {
                strcat(&fltstr, ch);
                continue;
            } 
            err = ERR_ILLEGAL_INPUT;
            return NAN;
        }
    }
    return atof(&fltstr);
}
/* @param operators: operator stack
 * @param out: operands stack
*/
static void _op(struct Stack* operators, struct Stack* out, char op) {
    push(operators, op);
    
    struct Node* current = operators->top;
    size_t depth = 0;
   
    for (struct Node* current; current != NULL; current = current->prev, depth++) {
        if (current->data == '*' || current->data == '/')
            break;
    }
    
    free(current);
    push(out, pop(operators, depth));

}

void _eval(struct Stack* out, char op) {
    float lflt = pop(out, 1);
    float rflt = pop(out, 0);
    float val;

    switch (op) {
        case '*':
            val = lflt * rflt;
        case '/':
            val = lflt / rflt;
        case '+':
            val = lflt + rflt; 
        case '-':
            val = lflt - rflt;
    }

    push(out, val);
}

float calculatea(char str[], char* err) {
    struct Stack out;
    struct Stack operators;
    float flt = NAN;
    for (char* ch = str; *ch != '\n'; ch++) {
        if (isdigit(*ch)) { //if operand push to out
            flt = _flt(ch, &out, err);
            if (err != NULL)
                return NAN;
            push(&out, flt);
            continue;
        }
        _op(&operators, &out, *ch);
    }

    free(operators.top);

    return out.top->data;
}
