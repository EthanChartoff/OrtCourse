#include <stdio.h>
#include "linked_stack.h"

int main() {
    Stack s = scan_and_sort_nums(5);
    while (!stack_empty(s)) {
        printf("%d ", pop(&s));
    }
    
    return 0;
}