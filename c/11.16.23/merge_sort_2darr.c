#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../sorts.h"

#define RAND_RANGE 1000

// make a 2d array from user inputs (the rows dont have to be the same length.
// returns arrays size.
int make_2d_arr(int ***arr) {
    int m, n;
    int i, j;
    int size = 0;

    printf("enter column length: ");
    scanf("%d", &m);
    *arr = malloc(m * sizeof(**arr));

    for(i = 0; i < m; ++i) {
        printf("enter row %d length: ", i);
        scanf("%d", &n);

        (*arr)[i] = calloc(n + 1, sizeof(***arr));

        for(j = 0; j < n; ++j) {
            // printf("enter element (besides -1) [%d][%d]", i, j);
            // scanf("%d", &(*arr)[i][j]);

            (*arr)[i][j] = rand() % RAND_RANGE;
        }
        (*arr)[i][n] = -1;
        size += n;
    }
    return size;
}

// return column size
static int put_2d_to_1d(int **twod, int **oned, size_t size) {
    int column, row, i;

    column = 0;
    row = 0;
    for(i = 0; i < size; ++i) {
        if(twod[column][row] == -1) {
            column++;
            row = 0;
        }
        (*oned)[i] = twod[column][row];
        row++;
    }
    return column;
}

int main() { 
    int **two_d_arr, *one_d_arr;
    int size, i, column;

    // initialize rng 
    srand(time(NULL));

    // make arrays
    size = make_2d_arr(&two_d_arr);
    one_d_arr = malloc(size * sizeof(**two_d_arr));
    column = put_2d_to_1d(two_d_arr, &one_d_arr, size);

    merge_sort(one_d_arr, size);

    for(i = 0; i < size; ++i) {
        printf("%d, ", one_d_arr[i]);
    }
    printf("\n");

    for(i = 0; i <= column; ++i)
        free(two_d_arr[i]);
    free(two_d_arr);
    free(one_d_arr);
}