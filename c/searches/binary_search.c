#include <stddef.h>

int binary_search(int a[], size_t n, int num) {
    int low, mid, high;

    low = 0;
    high = n - 1;
    while(low <= high) {
        mid = low + (high - low) / 2;

        if(a[mid] == num)
            return mid;
        // ignore left half
        else if(a[mid] > num)
            high = mid + 1;
        // ignore right half
        else 
            low = mid - 1;
    }

    return -1;
}