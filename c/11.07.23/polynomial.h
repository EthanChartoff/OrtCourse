typedef struct polynomial_node {
    float coeff;
    int pow;
    struct polynomial_node *next;
} polynomial_node;

polynomial_node* sum(polynomial_node* pol1, polynomial_node* pol2);
polynomial_node* create();