#include <stddef.h>

// ---iterative searches--- 
int linear_search(int a[], size_t n, int num);
int binary_search(int a[], size_t n, int num);
int ternary_search(int a[], size_t n, int num);

void find_min_max(int a[], int *min, int *max, size_t n);

// ---recursive searches--- 
int recursive_linear_search(int a[], size_t n, int num);
int recursive_binary_search(int a[], size_t n, int num);

// ---iterative sorts---
void merge_sort(int arr[], size_t n);
void selection_sort (int arr[], size_t n);
void bubble_sort(int arr[], size_t n);

// ---recursive sorts---
void recursive_selection_sort(int a[], size_t n);