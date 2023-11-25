#include <stddef.h>

int recursive_linear_search(int a[], size_t n, int num) {
    if(n == 0) 
        return -1;
    if(a[n-1] == num)
        return n-1;
    return recursive_linear_search(a, n-1, num);
}