#ifndef STACK_MAX_SIZE
#define STACK_MAX_SIZE 100
#endif

typedef int stack_item;	 // type of data in stack

typedef struct {
	int top;
	stack_item data[STACK_MAX_SIZE];
} Stack;

void stack_init(Stack *s);

int stack_empty(Stack s);

int stack_full(Stack s);

void push(Stack *s, stack_item x);

stack_item pop(Stack *s);

stack_item top(Stack s);

void flip(Stack *s);
