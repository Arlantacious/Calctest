#ifndef PARSER_H
#define PARSER_H

#include "../utils/error.h"
#include "../utils/token.h"
#include "../utils/stack.h"

Stack* parse(Token token, ERROR* err);

#endif
