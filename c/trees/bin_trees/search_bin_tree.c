#include "inc/search_bin_tree.h"
#include <stdlib.h>
#include <stdio.h>

search_bin_tree_T* init_search_bin_tree(int data) {
    search_bin_tree_T* t = (search_bin_tree_T*)malloc(sizeof(search_bin_tree_T));
    t->data = data;

    return t;
}

search_bin_tree_T* insert_value_from_root(search_bin_tree_T *t, int data) {
    if(data < t->data) {
        if(t->lesser == NULL) {
            t->lesser = init_search_bin_tree(data);
            return t->lesser;
        }
        return insert_value_from_root(t->lesser, data);
    }
    if(t->larger_equal == NULL) {
        t->larger_equal = init_search_bin_tree(data);
        return t->larger_equal;
    }
    return insert_value_from_root(t->larger_equal, data);
}

void insert_values_from_root(search_bin_tree_T *t, int *data, size_t length) {
    size_t i;

    for(i = 0; i < length; ++i) 
        insert_value_from_root(t, data[i]);
}

void print_pre_order(search_bin_tree_T *t) {
    printf("%d", t->data);
    print_pre_order(t->lesser);
    print_pre_order(t->larger_equal);
}

void print_in_order(search_bin_tree_T *t) {
    print_pre_order(t->lesser);
    printf("%d", t->data);
    print_pre_order(t->larger_equal);
}

void print_post_order(search_bin_tree_T *t) {
    print_pre_order(t->lesser);
    print_pre_order(t->larger_equal);    
    printf("%d", t->data);
}

void choose_print(search_bin_tree_T *t) {
    int choice = 1;
    void (*print_tree[])(search_bin_tree_T*) = {
        &print_pre_order,
        &print_in_order,
        &print_post_order
    };

    while (choice) {
        printf("choose how to print the given tree: \n0. stop printing \n1. pre order \n2. in order \n 3. post order\n");
        scanf("%d", &choice);

        if(!choice) {
            return;
        }
        print_tree[choice - 1](t);
    }
}   

int n_nodes(search_bin_tree_T *t) {
    if(t == NULL)
        return 0;

    return 1 + n_nodes(t->lesser) + n_nodes(t->larger_equal); 
}

int is_leaf(search_bin_tree_T *t) {
    if(t->lesser == NULL && t->larger_equal == NULL)
        return 1;
    return 0;
}   

int n_leafs(search_bin_tree_T *t) {
    if(t == NULL)
        return 0;
    if(is_leaf(t))
        return 1;
    return n_leafs(t->lesser) + n_leafs(t->larger_equal);
}



