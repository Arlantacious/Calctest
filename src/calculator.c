#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "calculator.h"
#include "utils.h"

static void _flt(char* ch, struct Stack* operands, char* err) {
    char fltstr;

    for (char* ch; *ch != '\n'; ch++) {
        if (isdigit(ch)) {
            strcat(&fltstr, ch);
            continue;
        } 
        if (*ch == '.') {
            if (strchr(&fltstr, '.') == NULL) {
                strcat(&fltstr, ch);
                continue;
            } 
            err = ERR_ILLEGAL_INPUT;
        }
    }

    push(operands, atof(&fltstr));
}

static void _op(struct Stack* operators, struct Stack* operands) {
    push(operators, operators->top->data);
    
    struct Node* current = operators->top;
    size_t depth = 0;
   
    for (struct Node* current; current != NULL; current = current->prev, depth++) {
        if (current->data == '*' || current->data == '/')
            break;
    }

    if (current == NULL)
        depth = 0;
    
    char op = current->data;
    
    pop(operators, depth);

    float lhs = pop(operands, 1);
    float rhs = pop(operands, 0);
    float val;

    switch (op) {
        case '*':
            val = lhs * rhs;
        case '/':
            val = lhs / rhs;
        case '+':
            val = lhs + rhs; 
        case '-':
            val = lhs - rhs;
    }

    push(operands, val);
    free(current);
}

float calculate(char str[], char* err) {
    struct Stack operands;
    struct Stack operators;

    for (char* ch = str; *ch != '\n'; ch++) {
        if (isdigit(ch)) {
            _flt(ch, &operands, err);
            continue;
        }
        _op(&operators, &operands);
    }

    free(operators.top);

    return operands.top->data;
}
