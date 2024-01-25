//===------------------------------------------------------------------------------===
// A binary tree using refrences made using pointers as a refrence to a node.
// This implemmentation is more dynamic and flexible then other implementations 
// but takes more memory and is less efficient.
// This will be a tree with no purticular type.
//===------------------------------------------------------------------------------===

typedef struct POINTER_BINARY_TREE_STRUCT {
    struct POINTER_BINARY_TREE_STRUCT *left;
    void* data;
    struct POINTER_BINARY_TREE_STRUCT *right;
} p_bin_tree_T;

// Initialize tree
p_bin_tree_T* init_p_bin_tree(void* data);

// Searches
void 

