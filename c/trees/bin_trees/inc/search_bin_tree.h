//===------------------------------------------------------------------------------===
// A bin search tree.
// The data in the tree consists of integers.
//===------------------------------------------------------------------------------===

#include <stddef.h>

typedef struct SEARCH_BINARY_TREE_STRUCT {
    struct SEARCH_BINARY_TREE_STRUCT *lesser;
    int data;
    struct SEARCH_BINARY_TREE_STRUCT *larger_equal;
} search_bin_tree_T;

// init
search_bin_tree_T* init_search_bin_tree(int data);

// Insertion
search_bin_tree_T* insert_value_from_root(search_bin_tree_T* t, int data);
void insert_values_from_root(search_bin_tree_T *t, int *data, size_t length);

// Prints
void print_pre_order(search_bin_tree_T *t);
void print_in_order(search_bin_tree_T *t);
void print_post_order(search_bin_tree_T *t);
void choose_print(search_bin_tree_T *t);

// Misc.
int n_nodes(search_bin_tree_T *t);
int n_leafs(search_bin_tree_T *t);
int is_leaf(search_bin_tree_T *t);