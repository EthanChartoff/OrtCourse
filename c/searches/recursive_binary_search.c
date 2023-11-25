#include <stddef.h>
#include <stdio.h>

int recursive_binary_search(int a[], size_t n, int num) {
    int mid, res;

    if(n == 0)
        return -1;
    res = -1;

    mid = (n-1) / 2;

    if(a[mid] == num)
        return mid;
    else {
        if(a[mid] > num)
            return recursive_binary_search(a, mid - 1, num);
        else {
            res = recursive_binary_search(a + mid + 1, n - mid - 1, num);
            if(res != -1)
                return res + mid + 1;
            else 
                return -1;
        }
    }
}