#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "../utils/stack.h"
#include "../utils/queue.h"
#include "../utils/token.h"
/*
 * @param operators: current operator queue
 * @return Token: return current token
 * @return Token: return dequeued token
 */
static Token _precedence(Queue* operators) {
    Queue_Node* prev = operators->front;
    Queue_Node* current = operators->front;

    while (current != NULL) {
        if (current->token.prec == TOKEN_PREC_HIGH) {
            prev->next  = current->next;
            free(prev);

            return current->token;
        }
        prev = current;
        current = current->next;
    }

    free(prev);
    free(current);

    return dequeue(operators);
}
/*
 * @param src: raw token array input
 * @return ERROR: error code
 */
static Queue* _rpn(Token* src, ERROR* err) {
    Queue* out = queue();
    Queue* operators = queue();

    for (Token* token = src; token != NULL; token++) {      
        if (token->kind  == TOKEN_KIND_OPERAND) {
            enqueue(out, *token);
        } else {
            enqueue(operators, *token);
            enqueue(out, dequeue(operators));
        } 
    }

    free(operators);

    return out;
}
/*
 * @param src: raw token array input
 * @param out: processed tokens output
 * @return ERROR: error code
 */
Queue* parse(Token src, ERROR* err) {

    Queue* out = _rpn(&src, err);

    if (err != SUCCESS) {   
        return out;;
    }

    return out;
}
