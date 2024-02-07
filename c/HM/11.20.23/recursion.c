#include <stdio.h>

#include "../linearly_linked_list.h"

// checks if p2 is in p1.
int P1(Node **p1, Node **p2) {
    if((*p2) == NULL)
        return 1;
    if((*p1) == NULL)
        return 0;
    if((*p1)->data == (*p2)->data && P1((*p1)->next, (*p2)->next)) 
        return 1;
    printf("%d", (*p1)->data);
    return P1((*p1)->next, (*p2));
}

int P2(Node *p1) {
    if(p1->next == NULL)
        return p1->data;
    return p1->data+P2(p1->next)*10;
}

int main() {
    Node *p1 = list_create();
    // Node *p2 = list_create();
    printf("%d", P1(p1, p1));
    return 0;
}