#include "sparse_mat.h"
#include <stdio.h>
#include <stdlib.h>

// TODO: everything in here.

void init(sparse_mat_node *m) {
    m = NULL;
}

sparse_mat_node* create() {
    sparse_mat_node *start, *tmp;

    init(start);
    tmp = start;
    int format;

    printf("")
    scanf()
}

int is_empty(sparse_mat_node *m) {
    return m == NULL;
}

// m: pointer to start of mat
void insert(sparse_mat_node **m, int row, int col, mat_type x) {
    // check if outer nodes are in row and col range, 
    // if not, insert new outer nodes. 
    sparse_mat_node *tmp;
    
}

void insert_row_after(sparse_mat_node *m, mat_type x) {
    sparse_mat_node *new_node;

    new_node = (sparse_mat_node *) malloc(sizeof(sparse_mat_node));
    if(!is_empty(sparse_mat_node)) {
        new_node->data = x;
        new_node->next_row = m->next_row;
    }
}
