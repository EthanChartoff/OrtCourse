typedef union EXPRESSION_STRUCT {
    char operand;
    int value;
} expr_T;

typedef struct EXPRESSION_TREE_STRUCT {
    struct POINTER_BINARY_TREE_STRUCT *left;
    expr_T expr;
    struct EXPRESSION_TREE_STRUCT *right;
} expr_tree_T;

expr_tree_T* init_expr_tree(char* equation);
float calculate(expr_tree_T* equation);