#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "calculator.h"
#include "utils.h"
/* @param ch: current character in string
 * @param out: operand stack
 * @param err: error message
 * @return: substring converted to float 
*/
static char _strflt(char* ch, struct Stack* out, char* err) {
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
    return fltstr;
}
/* @param operators: operator stack
 * @param out: operand stack
 * @param op: operator symbol
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
    push(out, *pop(operators, depth));

}
/* 
 * @param out: operand stack
 * @param op: operator symbol
 * @return: final value from top of output stack
*/
float _eval(struct Stack* out) {
    float lval;
    float rval;
    float val;
    for (struct Node* current = out->top; current != NULL; current = current->prev) {
        lval = atof(pop(out, 1));
        rval = atof(pop(out, 0));

        switch (current->data) {
            case '*':
                val = lval * rval;
            case '/':
                val = lval / rval;
            case '+':
                val = lval + rval; 
            case '-':
                val = lval - rval;
        }

        push(out, val);
    }
    return out->top->data;
}
/* @param str: input string
 * @param err: error message
 * @return: string to stack conversion in reverse polish notation
*/
struct Stack* _parse(char* str, char* err) {
    struct Stack* out;
    struct Stack operators;
    char flt;
    for (char* ch = str; *ch != '\n'; ch++) {
        if (isdigit(*ch)) { //if operand push to out
            flt = _strflt(ch, out, err);
            if (err != NULL)
                return NULL;
            push(out, flt);
            continue;
        }
        _op(&operators, out, *ch);
    }

    free(operators.top);

    return out;
}
/* @param str: input string
 * @param err: error message
 * @return: final value from top of output stack
*/
float calculate(char str, char* err) {
    struct Stack out = *_parse(&str, err);
    if (err != NULL)
        return NAN;
    float val = _eval(&out);
    return val;
}
