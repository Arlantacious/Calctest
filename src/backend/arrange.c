#include "arrange.h"


Exit_Code handle_val(Token token, Stack* out)
{
        if (token_eval_id(token.id))
        {
                stack_push(out, token);
                
                return SUCCESS;
        }

        return SAFE_FAIL;
}

Exit_Code resolve_high_prec(Token token, Stack* ops)
{
        if (stack_is_empty(ops) || token_cmp_prec(ops->top->data.id, token.id))
        {
                stack_push(ops, token);
        
                return SUCCESS;
        }

        return SAFE_FAIL;


}

Exit_Code resolve_low_prec(Token token, Stack* out,  Stack* ops)
{
        while (!stack_is_empty(ops) && !token_cmp_prec(token.id, ops->top->data.id))
        {
                stack_push(out, stack_pop(ops));
        }

        return SUCCESS;
}

Exit_Code resolve_push(Token token, Stack* ops)
{
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
        assert(arranged_src != NULL);

        Exit_Code err = SUCCESS;
        Stack out;
        Stack ops;

        stack_init(&out);
        stack_init(&ops);

        assert(out.top == NULL);
        assert(ops.top == NULL);

        for (Token* token = src; token->id != END; token++)
        {
                err = handle_val(*token, &out);

                if (err < 0)
                {
                        return err;
                }

                err = resolve_low_prec(*token, &out, &ops);

                if (err < 0)
                {
                        return err;
                }

                err = resolve_high_prec(*token, &ops);

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
        
        *arranged_src = out;

        return err;
}
