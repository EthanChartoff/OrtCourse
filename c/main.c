#include <stdio.h>
#include <stddef.h>
#include "linearly_linked_list.h"

int main() {
    Node *n1, *n2;
    
    list_init(&n1);
    list_init(&n2);
    list_scan_and_sort_2(&n1, &n2);
    list_print(n1);
    printf("\n");
    list_print(n2);
    
    return 0;
}