#ifndef PARSER_H
#define PARSER_H

#include "../utils/error.h"
#include "../utils/token.h"
#include "../utils/stack.h"
#include "../utils/queue.h"

Queue* parse(Token token, ERROR* err);

#endif
