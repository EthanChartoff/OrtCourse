#include <stddef.h>

void insertion_sort(int arr[], size_t n) {
    int i, j, val;

    for(i = 1; i < n; ++i) {
        val = arr[i];
        j = i-1;
        // moves elements to the right of the array until 
        // a value lesser then val is found
        while(j >=0 && arr[j] > val) {
            arr[j+1] = arr[j];
            --j;
        }
        // put val infront of the first element, so the sub-array will be sorted
        arr[j+1] = val;
    }
}