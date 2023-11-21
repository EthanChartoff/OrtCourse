#include <stdlib.h>

#include "circularly_doubly_linked_list.h"

void list_init(Node **list) {
    *list = NULL;
}

void list_insert_after(Node *node, list_type x) {
    Node *new_node;

    new_node = (Node *) malloc(sizeof(Node));
    if(new_node != NULL) {
        new_node->data = x;

        new_node->next = node->next;
        new_node->prev = node;
        node->next->prev = new_node;
        node->next = new_node;
    }
}  

// list points to the end of the list 
void list_insert_tail(Node **list, list_type x) {
    Node *new_node;

    new_node = (Node *) malloc(sizeof(Node));
    if(new_node != NULL) {
        new_node->data = x;
        if((*list) != NULL) {
            new_node->next = (*list)->next;
            new_node->prev = (*list);
            (*list)->next->prev = new_node;
            (*list)->next = new_node;
        } else {
            new_node->next = new_node;
            new_node->prev = new_node; 
        }
        *list = new_node;
    }
}

// TODO: may be incorrect
void list_insert_head(Node **list, list_type x) {
    Node *new_node;

    new_node = (Node *) malloc(sizeof(Node));
    if(new_node != NULL) {
        new_node->data = x;
        if((*list) != NULL) {
            new_node->next = (*list)->next;
            new_node->prev = (*list);
            (*list)->next->prev = new_node;
            (*list)->next = new_node;
        } else {
            new_node->next = new_node;
            new_node->prev = new_node;
            (*list) = new_node;
        }
    }
}

/// @brief create a cirularly ll that contains a big number that each 
/// @param big_num 
/// @return 
Node* create_big_num(uintmax_t big_num) {
    Node *num_list;

    list_init(&num_list);
    list_insert_head(&num_list, -1);
    while(big_num > 0) {
        list_insert_after(num_list, big_num % 10000);
        num_list = num_list->next;
        big_num /= 10000;
    }
    return num_list;
}
