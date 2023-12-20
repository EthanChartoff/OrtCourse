typedef int mat_type;

typedef struct sparse_mat {
    int row;
    int col;
    mat_type data;
    sparse_mat_node *next_row;
    sparse_mat_node *next_col
} sparse_mat_node;

// TODO: base funcs 
void init(sparse_mat_node *m);
sparse_mat_node* create();
int is_empty(sparse_mat_node *m);
void insert(sparse_mat_node *m, int row, int col, mat_type x);
void insert_row_after(sparse_mat_node *m, mat_type x);
void insert_col_after(sparse_mat_node *m, mat_type x);
mat_type* delete_row_after(sparse_mat_node *m);
mat_type* delete_col_after(sparse_mat_node *m);
mat_type* find_above(sparse_mat_node *m, int row, int col);
mat_type* find_before(sparse_mat_node *mat, int row, int col);

// not base funcs
void print(sparse_mat_node *m);
