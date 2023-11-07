#include <stdio.h>
#include <stdlib.h>

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

void Q3();

int main(void) {
    int* tmp;
    tmp = malloc(sizeof(int));

    Q2("Yosi and Avi live in Haifa", tmp);
    printf("%d\n", *tmp);
    free(tmp);

    return 0;
}