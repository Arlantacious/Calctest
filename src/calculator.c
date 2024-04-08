#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include "calculator.h"
#include "utils.h"
/*
 * @param ch: current character in string
 * @param err: error message
 * @return: subtring float segment
*/
static char _strval(char* ch, char* err) {
    char strval;

    for (char* ch = ch; *ch != '\n'; ch++) {
        if (isdigit(*ch)) {
            strcat(&strval, ch);
            continue;
        } 
        if (*ch == '.') {
            if (strchr(&strval, '.') == NULL) {
                strcat(&strval, ch);
                continue;
            } 
            err = ERR_ILLEGAL_INPUT;
            return NAN;
        }
    }
    return strval;
}
/* 
 * @param operators: operator stack
 * @param out: operand stack
 * @param op: operator symbol
*/
static void _op(struct Stack* operators, struct Stack* out, char op) {
    push(operators, &op);
    
    struct Node* current = operators->top;
    size_t depth = 0;
   
    for (struct Node* current; current != NULL; current = current->prev, depth++) {
        if (current->data[0] == '*' || current->data[0] == '/')
            break;
    }
    
    push(out, pop(operators, depth));
    free(current);
}
/* 
 * @param out: operand stack
 * @return: final value from top of output stack
*/
float _eval(struct Stack* out) {
    float lval;
    float rval;
    float val;

    for (struct Node* current = out->top; current != NULL; current = current->prev) {
        lval = atof(pop(out, 1));
        rval = atof(pop(out, 0));

        switch (current->data[0]) {
            case '*':
                val = lval * rval;
            case '/':
                val = lval / rval;
            case '+':
                val = lval + rval; 
            case '-':
                val = lval - rval;
        }

        char strval[sizeof(val)];
        snprintf(strval, val, "%f", val);
        push(out, strval);
    }

    return atof(out->top->data);
}
/* 
 * @param str: input string
 * @param err: error message
 * @return: string to stack conversion in reverse polish notation
*/
struct Stack* _parse(char* str, char* err) {
    struct Stack* out;
    struct Stack operators;
    char data;
 
    for (char* ch = str; *ch != '\n'; ch++) {
        if (isdigit(*ch)) {
            data = _strval(ch, err);
            if (err != NULL)
                return NULL;
            push(out, &data);
            continue;
        }
        _op(&operators, out, *ch);
    }

    free(operators.top);
    return out;
}
/* 
 * @param str: input string
 * @param err: error message
 * @return: final value from top of output stack
*/
double calculate(char str, char* err) {
    struct Stack out = *_parse(&str, err);

    if (err != NULL)
        return NAN;

    return _eval(&out);
}
