#include "inc/pointers_bin_tree.h"
#include <stdlib.h>
#include <stdio.h>

p_bin_tree_T* init_p_bin_tree(void* data) {
    p_bin_tree_T* t = (p_bin_tree_T*)malloc(sizeof(p_bin_tree_T));
    t->data = data;

    return t;
}

