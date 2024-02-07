#include "calculator_stack.h"

#include <stdio.h>
#include <stdlib.h>

/*
	A specialized stack designed to help calculate a simple binary math equation
*/

/// @brief Initialize a stack
/// @param s
void stack_init(Stack *s) { s->top = -1; }

/// @brief Check if a stack is empty
/// @param s
/// @return 1 if empty, 0 if not
int stack_empty(Stack s) { return s.top == -1; }

/// @brief Check if a stack is full
/// @param s
/// @return 1 if full, 0 if not
int stack_full(Stack s) { return s.top == STACK_MAX_SIZE - 1; }

/// @brief Push an item to the stack
/// @param s
/// @param x
void push(Stack *s, stack_item x) {
	if (!stack_full(*s)) s->data[++s->top] = x;
}

/// @brief Pop an item from the stack
/// @param s
/// @return
stack_item pop(Stack *s) { return s->data[s->top--]; }

/// @brief Get the top item from the stack
/// @param s
/// @return
stack_item top(Stack s) {
	if (!stack_empty(s)) return s.data[s.top];
}

/// @brief Flip a stack
/// @param s
void flip(Stack *s) {
	Stack temp;
	stack_init(&temp);

	while (!stack_empty(*s)) {
		push(&temp, pop(s));
	}

	*s = temp;
}

/// @brief Check if a stack item is a parenthesis
/// @param x
/// @return
int is_parenthesis(stack_item x) { return x == '(' || x == ')'; }

/// @brief Check if a stack item is an operator
/// @param x
/// @return
int is_operator(stack_item x) {
	return x == '+' || x == '-' || x == '*' || x == '/' || x == '^';
}

/// @brief Check if a stack item is a literal
/// @param x
/// @return
int is_literal(stack_item x) { return x >= '0' && x <= '9'; }

/// @brief Get the precedence of a stack item
/// @param x
/// @return
int precedence(stack_item x) {
	switch (x) {
		case '^':
			return 3;
		case '*':
		case '/':
			return 2;
		case '+':
		case '-':
			return 1;
		default:
			return 0;
	}
}

char *toString(Stack s) {
	char *str = (char *)malloc(sizeof(char) * 100);
	int i = 0;

	while (!stack_empty(s)) {
		str[i++] = pop(&s);
	}

	str[i] = '\0';

	flip(&s);

	return str;
}
