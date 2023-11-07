#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"

/// @brief initialize list.
/// @param n 
void list_init(node **n) {
    *n = NULL;
}

/// @brief insert a new element to the beginning of the list. 
/// @param head 
/// @param element 
void list_insert_to_head(node **head, list_type element) {
    node *new_node;

    new_node = (node*) malloc(sizeof(node));
    if(new_node != NULL) {
        new_node->data = element;
        new_node->next = *head; 
        *head = new_node;
    } 
}

/// @brief insert a new element to the list after a certain node.
/// @param n 
/// @param element 
void list_insert_after(node *n, list_type element) {
    node *new_node;
    
    new_node = (node*) malloc(sizeof(node));
    if(new_node != NULL) {
        new_node->data = element;
        new_node->next = n->next;
        n->next = new_node;
    }
}

/// @brief insert a new element to the end of the list.
/// @param n 
/// @param element 
void list_insert_end(node *n, list_type element) {
    node *new_node;

    new_node = (node*) malloc(sizeof(node));
    if(new_node != NULL) {
        new_node->data = element;
        while(n->next != NULL)
            n = n->next;
        n->next = new_node;
    }
}



/// @brief link to lists together into a new list. 
/// @param start 
/// @param end 
/// @param new_node 
void list_link(node *start, node *end, node **new_node) {
    (*new_node)->next = start;
    while(start->next != NULL)
        start = start->next;
    start->next = end;
}

/// @brief create a new list using user inputs.
/// @return head to new list.
node* list_create() {
    node *head, *last;
    int condition, n;
    list_init(&head);

    condition = scanf("%d", &n);
    while(condition) {
        if(head == NULL) {
            list_insert_to_head(&head, n);
            last = head;
        } else {
            list_insert_after(last, n);
            last = last->next;
        }

        condition = scanf("%d", &n);
    }
    return head;
}

void list_flip(node **n) {
    node *head;
    list_init(&head);

    while(*n != NULL) {
        list_insert_to_head(&head, (*n)->data);
        *n = (*n)->next;
    }
    
    *n = head;
}






