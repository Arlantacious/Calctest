#include "utils.h"


int token_eval_id(Token_ID id) 
{
        return id == VAL;
}

int  token_cmp_prec(Token_ID stack_id, Token_ID current_id) 
{
        return
        (stack_id < MUL && current_id > MUL) || 
        (stack_id < EXP && current_id > EXP);
}

void stack_init(Stack* stack)
{
        stack->top = NULL;
}

void stack_push(Stack* stack, Token data) 
{
        assert(stack != NULL);
        struct Node* node = malloc(sizeof(struct Node));
        assert(node != NULL);
        node->data = data;
        node->prev = stack->top;
        stack->top = node;
}

Token stack_pop(Stack* stack)
{
        assert(stack != NULL);
        assert(stack->top != NULL);
        Token tmp = stack->top->data;
        stack->top = stack->top->prev;
        return tmp;
}

int stack_is_empty(Stack* stack)
{
        assert(stack != NULL);
        return stack->top == NULL;
}

void stack_free(Stack* stack)
{
        assert(stack != NULL);
        
        while (stack->top != NULL)
        {
                struct Node* next = stack->top->prev;
                free(stack->top);
                stack->top = next;
        }

        assert(stack->top == NULL);
}
