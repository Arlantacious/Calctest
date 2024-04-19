I will provide you with most of the code for my calculator project. I am currently trying to test the functionality
of rearranging a test sample token array into correct order of reverse polish notation. The program currently executes
successfully, but does not function properly. I will also provide you with the output console message. Outside of trying
to fix this, asserts are recommended to help testing.

[utils.h]

typedef enum {
    SUCCESS = 0,
    ERROR_ILLEGAL_INPUT = 1
} Error;

typedef enum {
    VALUE,
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    END
} Token_ID;

typedef struct {
    float val;
    Token_ID id;
} Token;

struct Node {
    struct Node* next;
    struct Node* prev;
    Token data;
};

typedef struct {
    struct Node* top;
} Stack;

int isempty(Stack* stack);

void push(Stack* stack, Token data);

Token pop(Stack* stack, int depth);

void init_stack(Stack* stack);

void free_stack(Stack* stack);

[utils.c]

int isempty(Stack* src) {
    if (src->top == NULL)
        return 1;
    return 0;
}

void push(Stack* src, Token data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->prev = src->top;
    src->top = node;
}

Token pop(Stack* src, int depth) {
    if (depth == -1) {
        struct Node* tmp = src->top;
        src->top = src->top->prev;
        Token data = tmp->data;
        free(tmp);
        return data;
    }

    struct Node* tmp = src->top;

    while (depth > 0) {
        tmp = tmp->prev;
        depth--;
    }

    struct Node* next_node = tmp->prev;
    Token* data = &(tmp->data);

    if (next_node != NULL)
        next_node->next = tmp->next;

    return *data;
}

void init_stack(Stack* stack) {
    stack->top = NULL;
}

void free_stack(Stack* stack) {
    struct Node* current = stack->top;

    while (current != NULL) {
        struct Node* next = current->prev;
        free(current);
        current = next;
    }

    stack->top = NULL;
}

[calculator.c]

char* geterrmsg[] = {
    [SUCCESS] = "success",
    [ERROR_ILLEGAL_INPUT] = "illegal input"
};

int isprec(Token op1, Token op2) {
   if (op1.id == ADD || op1.id == SUBTRACT)
        if (op2.id == MULTIPLY || op2.id == DIVIDE)
            return 1;
   return 0;
}

Error rearrange(Token* src, Stack* out) {
    Stack ops;
    init_stack(&ops);

    for (; src->id != END; src++) {
        if (src->id == VALUE) {
            push(out, *src);
            continue;
        }

        if (isempty(&ops) || !isprec(ops.top->data, *src)) {
            push(&ops, *src);
            continue;
        }

        while (!isempty(&ops))
            push(out, pop(&ops, 0));
        
        push(&ops, *src);
    }
    assert(src->id == END);

    return SUCCESS;
}

char* calculate(Token src[]) {
    Error err = SUCCESS;
    Stack out;
    init_stack(&out);

    if (rearrange(src, &out) != SUCCESS)
        return geterrmsg[err];
    
    for (struct Node* current = out.top; current != NULL; current = current->prev) {
        if (current->data.id == VALUE) {
            printf("val: %f\n", current->data.val);
            continue;
        }

        printf("id: %d\n\n", current->data.id);
    }

    return geterrmsg[err];
}

[main.c]

int main(void) {
    Token t1;
    t1.val = 1;
    t1.id = VALUE;
    Token t2;
    t2.id = ADD;
    Token t3;
    t3.val = 2;
    t3.id = VALUE;
    Token t4;
    t4.id = SUBTRACT;
    Token t5;
    t5.val = 3;
    t5.id = VALUE;
    Token testin[] = { t1, t2, t3, t4 };
    size_t size = 4;
    char* errmsg = calculate(testin, size);

    fprintf(stderr, "%s", errmsg);
    return 0;
}

[console output]

val: 2.000000
val: 1.000000
exit: success%
