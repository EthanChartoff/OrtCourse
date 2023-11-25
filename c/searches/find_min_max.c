#include <stddef.h>

// algorithems, 6 page 3
void find_min_max(int a[], int *min, int *max, size_t n) {
    int tmp_min, tmp_max;

    if(n == 1) {
        *min = a[n-1];
        *max = a[n-1];
    } else {
        find_min_max(a, &tmp_min, &tmp_max, n-1);
        
        if(a[n-1] > tmp_min)
            *min = tmp_min;
        else 
            *min = a[n-1];
        
        if(a[n-1] < tmp_max)
            *max = tmp_max;
        else 
            *max = a[n-1];
    }
}