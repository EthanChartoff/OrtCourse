#include <stdio.h>

#include "polynomial.h"

int main(void) {
    polynomial_node *n1 = create();
    polynomial_node *n2 = create();

    polynomial_node *s;
    s = sum(n1, n2);

    while (s != NULL) {
        printf("%3fx^%d -> ", s->coeff, s->pow);
        s = s->next;
    }    
}