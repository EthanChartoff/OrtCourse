typedef int list_type;

typedef struct Node {
    list_type data;
    struct Node *next;
} Node;

// base functions 
void list_init(Node **n);
void list_insert_to_head(Node **head, list_type element);
void list_insert_after(Node *n, list_type element);
void list_insert_end(Node *n, list_type element);
void list_delete_head(Node **head);
void list_delete_after(Node *n);
int list_is_empty(Node *n);

// bonus functions from homework, projects etc...
void list_link(Node *start, Node *end, Node **new_Node);
Node* list_create();
void list_flip(Node **n);
void list_print(Node *n);
int list_is_in(Node **n);
int list_length(Node **n);
int list_biggest_diff(Node **n);
void list_split_oddeven(Node **n);
void list_scan_and_sort_2(Node **n1, Node **n2);
