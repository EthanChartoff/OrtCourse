#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void merge(int arr[], size_t n, int half) {
    int i, j, k;
    int llen = half;
    int rlen = n - half;
    int l[llen], r[rlen];

    memcpy(l, arr, llen * sizeof(*arr));
    memcpy(r, arr + llen, rlen * sizeof(*arr));

    i = 0;
    j = 0;
    k = 0;
    while(i < llen && j < rlen) {
        if(l[i] <= r[j]) {
            arr[k] = l[i];
            ++i;
        } else {
            arr[k] = r[j];
            ++j;
        }
        ++k;
    }

    memcpy(arr + k, l + i, (llen - i) * sizeof(*l));
    memcpy(arr + k, r + j, (rlen - j) * sizeof(*r));

}

static void merge_sort_rec(int arr[], size_t n) {
    if(n <= 1)
        return;
    
    int half = n / 2;

    // splits arr
    merge_sort_rec(arr, half);
    merge_sort_rec(arr + half, n - half);

    // merges two arrs
    merge(arr, n, half);
}

void merge_sort(int arr[], size_t n) {
    merge_sort_rec(arr, n);
}

