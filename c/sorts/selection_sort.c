#include <stddef.h>

void selection_sort(int arr[], size_t n) {
    int i, j, min_index, tmp;

    for(i = 0; i < n; ++i) {
        min_index = i;
        for(j = i + 1; j < n; ++j) {
            if(arr[min_index] > arr[j]) 
                min_index = j;
        }
        tmp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = tmp;
    }
}