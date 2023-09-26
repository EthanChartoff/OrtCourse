#include <stdlib.h>
#include <stdio.h>
#include "stack.h"


/// @brief Initialize a stack
/// @param s 
void stack_init(Stack *s)
{
    s->top = -1;
}

/// @brief Check if a stack is empty
/// @param s 
/// @return 1 if empty, 0 if not
int stack_empty(Stack s)
{
    return s.top == -1;
}

/// @brief Check if a stack is full
/// @param s 
/// @return 1 if full, 0 if not
int stack_full(Stack s)
{
    return s.top == STACK_MAX_SIZE - 1;
}

/// @brief Push an item to the stack
/// @param s 
/// @param x 
void push(Stack *s, stack_item x)
{
    if(!stack_full(*s)) s->data[++s->top] = x;
}

/// @brief Pop an item from the stack
/// @param s 
/// @return 
stack_item pop(Stack *s)
{
    return s->data[s->top--];
}

/// @brief Get the top item from the stack
/// @param s 
/// @return 
stack_item top(Stack s)
{
    if(!stack_empty(s)) return s.data[s.top];
}

/// @brief Flip a stack 
/// @param s 
void flip(Stack *s)
{
    Stack temp;
    stack_init(&temp);

    while(!stack_empty(*s))
    {
        push(&temp, pop(s));
    }

    *s = temp;
}

