#include "arrange.h"


static Exit_Code resolve_val(Token token, Stack* out)
{
        if (token_eval_id(token.id))
        {
                stack_push(out, token);
                
                return SUCCESS;
        }

        return SAFE_FAIL;
}

static Exit_Code resolve_op(Token token, Stack* out,  Stack* ops)
{
        while (!stack_is_empty(ops) && token_cmp_prec(token.prec, ops->top->data.prec))
        {
                stack_push(out, stack_pop(ops));
        }

        stack_push(ops, token);

        return SUCCESS;
}

Exit_Code resolve_final(Stack* out, Stack* ops) 
{
        while (!stack_is_empty(ops))
        {
                stack_push(out, stack_pop(ops));
        }

        return SUCCESS;
}

Exit_Code arrange(Token src[], Stack* arranged_src)
{
        Exit_Code err = SUCCESS;
 
        Stack out;
        Stack ops;
        stack_init(&out);
        stack_init(&ops);

        assert(out.top == NULL);
        assert(ops.top == NULL);

        for (Token* token = src; token->id != END; token++)
        {
                err = resolve_val(*token, &out);

                if (err < 0)
                {
                        return err;
                }

                if (err == SUCCESS)
                {
                        continue;
                }
                
                err = resolve_op(*token, &out, &ops);

                if (err < 0)
                {
                        return err;
                }
        }

        err = resolve_final(&out, &ops);

        if (err < 0)
        {
                return err;
        }
        
        stack_reverse(&out);
        *arranged_src = out;
        
        return err;
}
