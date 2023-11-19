#include <stdlib.h>
#include <stdio.h>

#include "linked_stack.h"

void stack_init(Stack *s) {
    s->top = NULL;
}

int stack_empty(Stack s) {
    return s.top == NULL;
}

void push(Stack *s, stack_type x) {
    Node *tmp;

    tmp = malloc(sizeof(Node));
    if(tmp != NULL) {
        tmp->data = x;
        tmp->next = s->top;
        s->top = tmp;
    }
}

stack_type pop(Stack *s) {
    stack_type tmp;

    if(s->top == NULL) {
        return NULL;
    }
    tmp = s->top->data;
    s->top = s->top->next;
    return tmp;
}

stack_type top(Stack s) {
    if(s.top == NULL) {
        return NULL;
    }
    return s.top->data;
}

// Reads n digits and arranges them (largest number is in top).
Stack scan_and_sort_nums(int n) {
    int i, num, format;
    Stack stk, tmp;

    stack_init(&stk);
    printf("please enter some numbers to be arranged in a stack:\n");

    for(i = 0; i < n; ++i) {
        format = scanf("%d", &num);
        getchar();
        while(!format) {
            printf("must be a number\n");
            format = scanf("%d", &num);
            getchar();
        }

        if(stack_empty(stk)) {
            push(&stk, num);
        } else {
            stack_init(&tmp);

            while (top(stk) > num)
                push(&tmp, pop(&stk));
                
            push(&stk, num);
            
            while (!stack_empty(tmp))
                push(&stk, pop(&tmp));
        }
    }
    return stk;
}