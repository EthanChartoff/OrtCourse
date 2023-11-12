#include <stdint.h>

typedef int list_type;

typedef struct Node {
    list_type data;
    struct Node *next;
} Node;

// base functions
void list_init(Node **list);
void list_insert_after(Node *node, list_type x);
void list_insert_tail(Node **list, list_type x);
void list_insert_head(Node **list, list_type x);
list_type list_delete_after(Node *n);
list_type list_delete_tail(Node **list);
list_type list_delete_head(Node **list);

// bonus functions from homework, projects etc...
Node* create_big_num(uintmax_t big_num);
Node* sum_big_num(Node **n1, Node **n2);