#include "utils.h"


int token_eval_id(Token_ID id) 
{
        return id == VAL;
}

int  token_cmp_prec(int stack_prec, int current_prec) 
{
        return current_prec >= stack_prec;
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
        assert(stack->top != NULL);
        Token tmp = stack->top->data;
        stack->top = stack->top->prev;
        return tmp;
}

void stack_reverse(Stack* stack)
{
        Stack tmp;
        stack_init(&tmp);
        
        while (!stack_is_empty(stack))
        {
                stack_push(&tmp, stack_pop(stack));
        } 

        *stack = tmp;
}

int stack_is_empty(Stack* stack)
{
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

void debug_print_tokens(Token* tokens)
{
        static char* get_lit[] =
        {
                [ADD] = "+",
                [SUB] = "-",
                [MUL] = "*",
                [DIV] = "/",
                [MOD] = "%",
                [EXP] = "^"
        };
        
        printf("tokens: ");

        for (; tokens->id != END; tokens++)
        {
                if (token_eval_id(tokens->id))
                {
                        printf("%d", (int)tokens->val);
                        continue;
                }

                printf("%s", get_lit[tokens->id]);
        }

        printf("\n");
}

void debug_print_stack(Stack stack)
{
        static char* get_lit[] =
        {
                [ADD] = "+",
                [SUB] = "-",
                [MUL] = "*",
                [DIV] = "/",
                [MOD] = "%",
                [EXP] = "^"
        };

        printf("stack: ");

        while (!stack_is_empty(&stack))
        {
                if (token_eval_id(stack.top->data.id))
                {
                        printf("%d", (int)stack_pop(&stack).val);
                        continue;
                }

                printf("%s", get_lit[stack_pop(&stack).id]);
        }

        printf("\n");
}
