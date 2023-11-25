#include <stdio.h>
#include "../recursive_algos.h"

void pascals_triangle(unsigned int n) {
    int i, j;
    for(i = 0; i < n; ++i) {
        for(j = 0; j <= i; ++j) {
            printf("%ld ", choose(i, j));
        }
        printf("\n");
    }
}