typedef int list_type;

/// @brief Contains a node of a linked list, a data field and a pointer to the next node
typedef struct node {
    list_type data;
    struct node *next;
} node;

/// @brief Pointer to the first node of a linked list
typedef struct {
    node *head;
} list;


/// @brief Initialize a linked list
/// @param l
void list_init(list *l);

/// @brief free a linked list
/// @param l 
void list_free(list *l);

/// @brief Check if a linked list is empty
/// @param l
int list_empty(list *l);

/// @brief Get the last node of a linked list
/// @param l 
/// @return 
node *list_top(list *l);

/// @brief Pop a node from the list
/// @param l 
/// @return 
node *list_pop(list *l);

/// @brief Push a node to the end of a linked list
/// @param l 
/// @param node 
void list_push(list *l, node *n);

/// @brief Insert a node after a node
/// @param n
/// @param new_n
void list_insert_after(node *n, node *new_n);

/// @brief Insert a node to the beginning of a linked list
/// @param l 
/// @param n 
void list_insert_beginning(list *l, node *n);

/// @brief Remove the node after this node
/// @param n 
void list_remove_after(node *n);

/// @brief Remove the head node of a linked list
/// @param l
void list_remove_beginning(list *l);

/// @brief Find a node in a linked list
/// @param l
/// @param x
/// @return
node *list_find(list *l, list_type x);

/// @brief Convert a linked list to a string
/// @param l 
/// @return 
char *to_string(list *l);


