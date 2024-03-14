#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    int height;
    struct node *left;
    struct node *right;
} Node;

int max_int(int a, int b)  // Return the maximum of two integers
{
   return a > b ? a : b;
}

int height(Node *node)  // Calculate the height of a node
{
   if (node == NULL) {
       return -1;  // Height of an empty tree is -1
   } else {
       return node->height;
   }
}

Node *rotate_right(Node *node)  // Perform a right rotation
{
   Node *new_root = node->left;
   node->left = new_root->right;
   new_root->right = node;

   // Update heights after rotation
   node->height = max_int(height(node->left), height(node->right)) + 1;
   new_root->height = max_int(height(new_root->left), node->height) + 1;

   return new_root;  // Return the new root node
}

Node *rotate_left(Node *node)  // Perform a left rotation
{
   Node *new_root = node->right;
   node->right = new_root->left;
   new_root->left = node;

   // Update heights after rotation
   node->height = max_int(height(node->left), height(node->right)) + 1;
   new_root->height = max_int(height(new_root->right), node->height) + 1;

   return new_root;  // Return the new root node
}

Node *double_rotate_right(Node *node)  // Perform a double right rotation
{
   node->left = rotate_left(node->left);  // Left rotation on left subtree
   return rotate_right(node);            // Right rotation on root
}

Node *double_rotate_left(Node *node)  // Perform a double left rotation
{
   node->right = rotate_right(node->right); // Right rotation on right subtree
   return rotate_left(node);             // Left rotation on root
}

Node *insert(Node *node, int key)  // Insert a new key into the tree
{
   if (node == NULL) {
       // Create a new node if the tree is empty
       node = (Node *)malloc(sizeof(Node));
       if (node == NULL) {
           printf("Out of space\n");
           exit(1);
       } else {
           node->key = key;
           node->height = 0;  // Height of a new leaf node is 0
           node->left = node->right = NULL;
       }
   } else if (key < node->key) {
       // Recursively insert into the left subtree
       node->left = insert(node->left, key);

       // Balance the tree if needed after insertion
       if (height(node->left) - height(node->right) == 2) {
           if (key < node->left->key) {
               node = rotate_right(node);
           } else {
               node = double_rotate_right(node);
           }
       }
   } else if (key > node->key) {
       // Recursively insert into the right subtree
       node->right = insert(node->right, key);

       // Balance the tree if needed after insertion
       if (height(node->right) - height(node->left) == 2) {
           if (key > node->right->key) {
               node = rotate_left(node);
           } else {
               node = double_rotate_left(node);
           }
       }
   }

   // Update the height of the current node
   node->height = max_int(height(node->left), height(node->right)) + 1;

   return node;  // Return the updated root node
}


Node *delete_node(Node *node, int key)  // Delete a node with the given key
{
    if (node == NULL) {  // Base case: empty tree
        return NULL;
    }

    if (key < node->key) {  // Search for the key in the left subtree
        node->left = delete_node(node->left, key);

        // Balance the tree if needed after deletion
        if (height(node->right) - height(node->left) == 2) {
            if (height(node->right->left) > height(node->right->right)) {
                node = double_rotate_left(node);
            } else {
                node = rotate_left(node);
            }
        }
    } else if (key > node->key) {  // Search for the key in the right subtree
        node->right = delete_node(node->right, key);

        // Balance the tree if needed after deletion
        if (height(node->left) - height(node->right) == 2) {
            if (height(node->left->right) > height(node->left->left)) {
                node = double_rotate_right(node);
            } else {
                node = rotate_right(node);
            }
        }
    } else {  // Found the node to be deleted
        if (node->left != NULL && node->right != NULL) {  // Node has two children
            Node *temp = node->right;
            while (temp->left != NULL) {  // Find the in-order successor
                temp = temp->left;
            }
            node->key = temp->key;  // Replace node's key with successor's key
            node->right = delete_node(node->right, node->key);  // Delete the successor

            // Balance the tree if needed after deletion
            if (height(node->left) - height(node->right) == 2) {
                if (height(node->left->right) > height(node->left->left)) {
                    node = double_rotate_right(node);
                } else {
                    node = rotate_right(node);
                }
            }
        } else {  // Node has at most one child
            Node *temp = node;
            if (node->left == NULL) {
                node = node->right;  // Replace node with its right child
            } else if (node->right == NULL) {
                node = node->left;   // Replace node with its left child
            }
            free(temp);              // Free the memory of the deleted node
        }
    }

    if (node != NULL) {  // Update the height of the current node
        node->height = max_int(height(node->left), height(node->right)) + 1;
    }

    return node;  // Return the updated root node
}

void print_tree(Node *node)  // Print the tree in in-order traversal
{
    if (node != NULL) {
        print_tree(node->left);
        printf("%d ", node->key);
        print_tree(node->right);
    }
}
