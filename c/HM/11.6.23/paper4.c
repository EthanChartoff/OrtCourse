#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// @brief changes n to a pointer that points to how many digits a number has and how many digits divide by 3. 
/// @param n 
void Q1(int n, int *results) {    
    while(n > 0) {
        if((n % 10) % 3 == 0) 
            results[1]++;
        results[0]++;
        n /= 10;
    }
}

/// @brief gets a string and counts how many words 
/// in the string start with a lower case char.
/// @param str 
/// @param counter 
void Q2(const char *str, int *counter) {
    int i;
    int start_of_word_flag = 1;
    char curr;

    *counter = 0;
    for(i = 0, curr = *str; curr != '\0'; ++i) {
        curr = *(str + i);
        if(start_of_word_flag && curr >= 'a' && curr <= 'z')
            (*counter)++;
        if(curr == ' ') {
            start_of_word_flag = 1;
        } else {
            start_of_word_flag = 0;
        }
    }
}

void Q3() {
    char word[] = "abcdecq";
    char *s = word;
    char *s1 = &word[1];

    printf ("%ld\n", s1 - s); // 1
    printf ("%d\n", *(s1 + 3) - word[2]); // 2
    printf ("%s\n", s++); // abcdecq 
    printf ("%s\n", ++s); // cdecq
    printf ("%c\n", s[*s - *s + 2]); // e 
    printf ("%c\n", s[*s - *(s - 2)]); // e
}

void Q4() {
    int Arr[20], *pPtr, Num;
    pPtr = Arr;

    // Arr++; // not legal
    // Arr = &Num; // not legal
    // pPtr++; // legal
    // pPtr = &Num; // legal
    // *pPtr = 8; // legal
    // *Num = 8; // not legal
    // Arr+2 = 8; // not legal
    // Num = &8; // not legal
    // Num = &Arr[&5]; // not legal
    // Num = *pPtr; // legal
}

/// @brief 
/// @param arr 
/// @param n 
/// @return max value 
double Q5a(double *arr, size_t n) {
    double max = arr[0];
    int i;

    for(i = 1; i < n; ++i) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

/// @brief 
/// @param arr 
/// @param n 
/// @return address max value
double* Q5b(double *arr, size_t n) {
    int imax = 0;
    int i;

    for(i = 1; i < n; ++i) {
        if(arr[imax] < arr[i]) {
            imax = i;
        }
    }
    return &arr[imax];
}

/// @brief swap indexes of max and min elements.
/// @param arr 
/// @param n 
void Q6(double *arr, size_t n) {
    int imax, imin, i;
    double tmp;

    if(*arr > *(arr + 1)) {
        imax = 0;
        imin = 1;
    } else {
        imax = 1;
        imin = 0;
    }

    for(i = 2; i < n; ++i) {
        if(*(arr + i) > *(arr + imax)) {
            imax = i;
        } else if (*(arr + i) < *(arr + imin)) {
            imin = i;
        }
    }

    tmp = *(arr + imax);
    *(arr + imax) = *(arr + imin);
    *(arr + imin) = tmp;
}

/// @brief finds if str2 is in str1
/// @param str1 
/// @param str2 
/// @return 
char* Q7(char *str1, char *str2) {
    int i, j, flag;

    for(i = 0; i < strlen(str1); ++i) {
        flag = 1;
        for(j = 0; j < strlen(str2); ++j) {
            if(str1[i + j] != str2[j]) {
                flag = 0;
            }
        }
        if(flag) return &str1[i]; 
    }
    return NULL;
}

/// @brief max value
/// @param arr 
/// @param n 
/// @return 
double Q8(double *arr, size_t n) {
    if(n == 1) 
        return arr[0];
    
    double tmp = Q8(&arr[1], n - 1);    
    return tmp > arr[0] ? tmp : arr[0];
}

int main(void) {
    return 0;
}