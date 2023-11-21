#include <stdio.h>
#include <stddef.h>
#include "circularly_doubly_linked_list.h"

int main() {
    Node *s;

    s = create_big_num(123456)->next->next;
    while(s->data != -1) {
        printf("%d ->",s->data);
        s = s->next;
    }
    
    return 0;
}