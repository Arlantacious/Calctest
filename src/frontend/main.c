#include <stdio.h>
#include "../backend/arrange.h"
#include "../backend/utils.h"


int main(void) {
        Token t1 = {1, VAL}; 
        Token t2 = {0, ADD};
        Token t3 = {2, VAL};
        Token t4 = {0, SUB};
        Token t5 = {3, VAL};
        Token t6 = {0, MUL};
        Token t7 = {4, VAL};
        Token t8 = {0, DIV};
        Token t9 = {5, VAL};
        Token t10 = {0, END};

        Token test_src[] = { t1, t2, t3, t4, t5, t6, t7, t8, t9, t10 };

        Stack arranged_src; 
        stack_init(&arranged_src); 

        Exit_Code exit_code = arrange(test_src, &arranged_src); 

        #define MAX_TOKENS 10

        Token ordered_src[MAX_TOKENS]; 
        int token_count = 0;

        while (!stack_is_empty(&arranged_src) && token_count < MAX_TOKENS)
        {
                ordered_src[token_count] = stack_pop(&arranged_src);
                token_count++; 
        }

        for (int i = 0; i < token_count; i++)
        {
                if (ordered_src[i].id == VAL)
                { 
                        printf("Value: %f\n", ordered_src[i].val);
                } else
                {
                        printf("Operator ID: %d\n", ordered_src[i].id); 
                }
        }
        
        char* get_id_lit[] =
        {
                [ADD] = "+",
                [SUB] = "-",
                [MUL] = "*",
                [DIV] = "/",
                [MOD] = "%",
                [EXP] = "^"
        };
        
        printf("literal: ");

        for (int i = 0; i < token_count; i++)
        {
                if (ordered_src[i].id == VAL)
                {
                        printf("%d", (int)ordered_src[i].val);
                } else
                {
                        printf("%s", get_id_lit[ordered_src[i].id]);
                }
        }

        fprintf(stderr, "Exit code: %d\n", exit_code); 

        return 0; 
}
