#include "../sorts.h"
#include <stdio.h>

int main(void) {
    int a[] = {2, 5, 1, 6};

    merge_sort(a, 4);
    printf("%d", *a);
}