typedef int list_type;

/// @brief Contains a node of a linked list, a data field and a pointer to the next node
typedef struct node {
    list_type data;
    struct node *next;
} node;

// base functions 
void list_init(node **n);
void list_insert_to_head(node **head, list_type element);
void list_insert_after(node *n, list_type element);
void list_insert_end(node *n, list_type element);
void list_delete_head(node **head);
void list_delete_after(node *n);
int list_is_empty(node *n);

// bonus functions from homework, projects etc...
void list_link(node *start, node *end, node **new_node);
node* list_create();
void list_flip(node **n);
