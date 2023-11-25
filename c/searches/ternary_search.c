// improvment by factor of binary search
int ternary_search(int a[], size_t n, int num) {
    int l, r, mid1, mid2;

    l = 0;
    r = n - 1;
    while(l <= r) {
        mid1 = l + (r - l) / 3;
        mid2 = r - (r - l) / 3;

        if(num == a[mid1])
            return mid1;
        else if(num == a[mid2])
            return mid2;
        else if(num > a[mid2])
            l = mid2 + 1;
        else if(num < a[mid1]) 
            r = mid1 - 1;
        else {
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }
    return -1;
}