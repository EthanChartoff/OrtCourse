#include <stddef.h>

void bubble_sort(int arr[], size_t n) {
    int i, j, tmp, sorted = 0;

    for(i = 0; i < n - 1 && !sorted; ++i) {
        sorted = 1;

        for(j = 0; j < n - 1; ++j) {
            if(arr[j] > arr[j+1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                sorted = 0;
            }
        }
    }
}