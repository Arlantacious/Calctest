#include <stdio.h>
#include "../backend/arrange.h"
#include "../backend/process.h"
#include "../backend/utils.h"


#define MAX_TOKENS 14


int main(void) {

        char* get_lit[] =
        {
                [ADD] = "+",
                [SUB] = "-",
                [MUL] = "*",
                [DIV] = "/",
                [MOD] = "%",
                [EXP] = "^"
        };

        Token t1 = {1, VAL, 0};
        Token t2 = {0, ADD, 1};
        Token t3 = {2, VAL, 0};
        Token t4 = {0, SUB, 1};
        Token t5 = {3, VAL, 0};
        Token t6 = {0, MUL, 2};
        Token t7 = {4, VAL, 0};
        Token t8 = {0, DIV, 2};
        Token t9 = {5, VAL, 0};
        Token t10 = {0, MOD, 3};
        Token t11 = {6, VAL, 0};
        Token t12 = {0, EXP, 4};
        Token t13 = {7, VAL, 0};
        Token t14 = {0, END, 0};

        Token test_src[] = { t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14 };
                        
        Stack arranged_src; 
        stack_init(&arranged_src); 

        Exit_Code exit_code = arrange(test_src, &arranged_src); 
        
        Stack arranged_src_cpy = arranged_src;

        //float answer = process(&arranged_src_cpy);



        Token ordered_src[MAX_TOKENS]; 
        int token_count = 0;

        printf("input: ");

        for (int i = 0; test_src[i].id != END; i++)
        {
                if (test_src[i].id == VAL)
                {
                        printf("%d", (int)test_src[i].val);
                        continue;
                }
                printf("%s", get_lit[test_src[i].id]);
        }

        while (!stack_is_empty(&arranged_src) && token_count < MAX_TOKENS)
        {
                ordered_src[token_count] = stack_pop(&arranged_src);
                token_count++; 
        }
 
        printf("\noutput: ");

        for (int i = token_count - 1; i >= 0; i--)
        {
                if (ordered_src[i].id == VAL)
                {
                        printf("%d", (int)ordered_src[i].val);
                        continue;
                }
                printf("%s", get_lit[ordered_src[i].id]);
        }
        
        //printf("\nanswer: %f", answer);

        printf("\nexit: %d\n", exit_code);

        return 0; 
}
