#include <stddef.h>

int linear_search(int a[], size_t n, int num) {
    int i, counter;

    for(i = 0; i < n; ++i)
        if(a[i] == num)  
            return i;
    return -1;
}

