#include "../headers/lexr.h"
#include <ctype.h>

void _remv_whitspc(char* in) {

        char* src = in;
        char* dst = in;

        while (*src) {
                if (!isspace(*src)) {
                        *dst = *src;
                        dst++;
                }
                src++;
        }
        *dst = '\0';
}

void lex(char* in) {
        _remv_whitspc(in);
}
