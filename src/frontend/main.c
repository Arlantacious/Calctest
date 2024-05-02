#include <stdio.h>
#include "../backend/arrange.h"
#include "../backend/process.h"
#include "../backend/utils.h"


int main(void) {
        
        Exit_Code exit_code = SUCCESS;

        Stack arranged_src; 
        stack_init(&arranged_src); 
       
        Token t1 = { 1, VAL, 0 };
        Token t2 = { 0, ADD, 1 };
        Token t3 = { 2, VAL, 0 };
        Token t4 = { 0, SUB, 1 };
        Token t5 = { 3, VAL, 0 };
        Token t6 = { 0, MUL, 2 };
        Token t7 = { 4, VAL, 0 };
        Token t8 = { 0, DIV, 2 };
        Token t9 = { 5, VAL, 0 };
        Token t10 = { 0, MOD, 3 };
        Token t11 = { 6, VAL, 0 };
        Token t12 = { 0, EXP, 4 };
        Token t13 = { 7, VAL, 0 }; 

        Stack test_src;
        stack_init(&test_src); 

        stack_push(&test_src, t13);
        stack_push(&test_src, t12);
        stack_push(&test_src, t11);
        stack_push(&test_src, t10);
        stack_push(&test_src, t9);
        stack_push(&test_src, t8);
        stack_push(&test_src, t7);
        stack_push(&test_src, t6);
        stack_push(&test_src, t5);
        stack_push(&test_src, t4);
        stack_push(&test_src, t3);
        stack_push(&test_src, t2);
        stack_push(&test_src, t1);

        exit_code = arrange(&test_src, &arranged_src);  

        printf("input: ");
        
        debug_print_stack(test_src);
     
        printf("output: ");

        debug_print_stack(arranged_src);

        float answer;
        exit_code = process(&arranged_src, &answer);
        
        printf("answer: %f\n", answer);

        printf("exit: %d\n", exit_code);

        return 0; 
}
