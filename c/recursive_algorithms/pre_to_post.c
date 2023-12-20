#include <string.h>
#include <ctype.h>
#include <stdio.h>

// TODO: not working, need to fix.
void pre_to_post(char *pre, char *post) {
    char tmp;

    if(strlen(pre) == 0) {
        *post = '\0';
        return;
    } else {
        tmp = *pre++;
        if(isdigit(tmp) || isalpha(tmp)) {
            *post++= tmp;
        } else {
            pre_to_post(pre, post);
            pre_to_post(pre, post);
            *post++ = tmp;
        }
    }
}