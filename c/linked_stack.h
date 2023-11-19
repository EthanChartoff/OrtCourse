typedef int stack_type;

typedef struct Node {
    stack_type data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;


// base functions
void stack_init(Stack *s);
int stack_empty(Stack s);
void push(Stack *s, stack_type x);
stack_type pop(Stack *s);
stack_type top(Stack s);

// bonus functions

// Reads n digits and arranges them (largest number is in top).
Stack scan_and_sort_nums(int n);