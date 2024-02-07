#ifndef STACK_MAX_SIZE
#define STACK_MAX_SIZE 100
#endif

/*
	A specialized stack designed to help calculate a simple binary math equation
*/

typedef unsigned char stack_item;  // type of data in stack

typedef struct {
	int top;						  // index of top item in stack
	stack_item data[STACK_MAX_SIZE];  // array of stack items
} Stack;

// normal stack functions

void stack_init(Stack *s);

int stack_empty(Stack s);

int stack_full(Stack s);

void push(Stack *s, stack_item x);

stack_item pop(Stack *s);

stack_item top(Stack s);

void flip(Stack *s);

char *toString(Stack s);

// helpful functions for this specific stack

int is_parenthesis(stack_item x);

int is_operator(stack_item x);

int is_literal(stack_item x);

int precedence(stack_item x);
