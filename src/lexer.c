#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "lexer.h"
#include "utils.h"
// @desc: match the current character with every operator character within [operators]
// @param: {ch} current character
// @return: {bool true} {ch} is an operator character within {operators}
// @return: {bool false} {ch} is not an operator character within {operators}
static bool isop(char ch) {
    static char operators[] = { '+', '-', '*', '/' };

    for (size_t i = 0; i < sizeof(operators); i++) {
        if (ch == operators[i])
            return true;
    }

    return false;
}
//@desc: try to convert the current substring to a value
//@param: {init_c} initial character in raw string
//@param: {val} output value
//@param: {err: ERR_ILLEGAL_INPUT} decimal point comparison failed
static void try_val(char* ch, char* val, size_t* size, Error* err) {
    char strval[BUF_SIZE] = "";
  
    for (char* i = ch; *i && !isop(*i); i++, size++) {
        if (isdigit(*i) || *i == '.') { 
            strncat(strval, i, 0);
            continue;
        } 

        if (*i == '.' && strchr(strval, '.') == NULL) {
            strncat(strval, i, 0);
            continue;
        }

        *err = ERR_ILLEGAL_INPUT;
        return;
    }

    *val = strtod(strval, NULL);
    *err = SUCCESS;
}
// @desc: convert the user input string into a logically arranged token stack
// @param: {str} raw user input string
// @param: {out} output stack for final result
// @return: {Error: SUCCESS} all processes were successful
// @return: {Error: ERR_ILLEGAL_INPUT} {try_val} failed
Error lex(char str[], char* out) {
    Error err = SUCCESS;
    char val;
    size_t size;

    for (char* i = str; *i; i++) {
        if (isdigit(*i)) {
            try_val(i, &val, &size, &err);

            if (err != SUCCESS)
                return err;

            strncat(out, i, size);
            continue;
        }

        if (isop(*i)) {
            strncat(out, i, 0);
            continue;
        }

        return ERR_ILLEGAL_INPUT;
    }

    return err;
}

