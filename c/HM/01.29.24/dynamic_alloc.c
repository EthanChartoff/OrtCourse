#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void Q1(int n) {
    int *arr, i;

    arr = malloc(n * sizeof(int));
    for(i = 0; i < n; ++i) {
        arr[i] = i;
        printf("%d, ", arr[i]);
    }
    printf("\n");

    return;
}

int* EvenSubArray(int A[], int n, int *PnEven) {
    int even_count = 0, *even_arr, i;

    for(i = 0; i < n; ++i) {
        if(A[i] % 2 == 0) {
            even_arr = (int *) realloc(even_arr, (even_count + 1) * sizeof(int));
            even_arr[even_count] = A[i];
            even_count++;
        }
    }
    *PnEven = even_count;
}

void SearchLongestWord(char S[], char **L) {
    int i, j, count = 0, max = 0, flag = 1;
    char *tmp, *max_word;

    for(i = 0; flag; ++i) {
        if(S[i] == '\0')
            flag = 0;

        if(isalpha(S[i])) {
            tmp = realloc(tmp, count + 1);
            tmp[count] = S[i];
            count++;
        }
        else {
            if(count > max) {
                max = count;

                max_word = realloc(max_word, max + 1);

                for(j = 0; j < max; ++j) {
                    max_word[j] = tmp[j];
                }
                max_word[j] = '\0';
            }
            count = 0;            
        }
    }
    free(tmp);
    free(max_word);
}

void Q4(int HowManyDigits, int HowManyNums) {
    int i, j, tmp, nums_mat[HowManyNums][HowManyDigits];

    for(i = 0; i < HowManyNums; ++i) {
        scanf("%d", &tmp); 
        tmp = tmp % (int) pow(10, HowManyDigits);   
        for(j = 0; j < HowManyDigits; ++j) {
            nums_mat[i][HowManyDigits - j - 1] = tmp % 10;
            tmp /= 10;
        }
    }
}

int main(void) {
    Q4(4, 4);
    return EXIT_SUCCESS;
}