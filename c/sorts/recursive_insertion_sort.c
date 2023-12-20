#include <stddef.h>

void recursive_insertion_sort(int arr[], size_t n) {
    if(n <= 1)
        return;
    
    recursive_insertion_sort(arr, n-1);
    int i, val;
    val = arr[n - 1];
    i = n - 2;

    while(i >= 0 && arr[i] > val) {
        arr[i+1] = arr[i];
        --i;
    }
    arr[i+1] = val;

}