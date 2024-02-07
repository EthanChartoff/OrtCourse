#include <stdio.h>
#include <stdlib.h>

/// @brief gets a mat and checks if the mat is a latin cube.
/// @param size 
/// @param mat 
/// @return 
int Q1(size_t size, int mat[][size]) {
    int i, j;
    int **sum_mat;
    int curr, sum;

    // the first row wil have the sum of all rows, and the second
    // row will have the sums of all the columns.
    sum_mat = (int **)malloc(size * sizeof(int *));

    for(i = 0; i < size; ++i) {
        sum_mat[i] = (int *)calloc(2, sizeof(int));
    }

    for(i = 0; i < size; ++i) {
        sum += i + 1; // calc sum of all different numbers in the latin square. 

        for(j = 0; j < size; ++j) {
            curr = mat[i][j];
            if(curr > 0 && curr <= size) {
                sum_mat[0][i] += curr;
                sum_mat[1][j] += curr;
            } else {
                return 1;
            }
        }
    }

    // check if all sums of rows and columns are equal to sum
    for(i = 0; i < 2; ++i) {
        for(j = 0; j < size; ++j) {
            if(sum_mat[i][j] != sum) {
                return 1;
            }
        }
    }
    
    return 0;
}

/// @brief 
/// @param rows 
/// @param columns 
/// @param mat 
/// @return an arr with all the numbers that are in all the rows and columns 
int* Q2(size_t rows, size_t columns, int mat[][columns]) {
    int i, j, k;
    int *first_row, *result;
    int *options; // if element is 1: seen in row/column
                  //               0: not seen yet
                  //              -1: not seen previously, so dont bother 

    first_row = (int *) malloc(columns * sizeof(int));
    result = (int *) malloc(columns * sizeof(int));
    options = (int *) calloc(columns, sizeof(int));

    for(i = 0; i < columns; ++i) {
        first_row[i] = mat[0][i];
    }

    for(i = 0; i < rows; ++i) {
        for(j = 0; j < columns; ++j) {
            if(options[j] != -1) {
                options[j] = 0;
            }
        }

        for(j = 0; j < columns; ++j) {
            for(k = 0; k < columns; ++k) {
                if(first_row[k] == mat[i][j] && options[k] != -1)
                    options[k]++;
            }
        }
    } 

    for(i = 0; i < columns; ++i) {
        for(j = 0; j < columns; ++j) {
            if(options[j] != -1) {
                options[j] = 0;
            }
        }

        for(j = 0; j < rows; ++j) {
            for(k = 0; k < columns; ++k) {
                if(mat[j][i] == first_row[k] && options[k] != -1) {
                    options[k]++;
                }
            }
        }
    }

    for(i = 0, j = 0; i < columns; ++i) {
        if(options[i] == 1) {
            result[j] = first_row[i];
            j++; 
        }
    }
    result = (int *) realloc(result, j * sizeof(int));

    return result;
}