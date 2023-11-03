#include <stdio.h>
#include <stdlib.h>

#include "node.h"

/// @brief Initialize a linked list
/// @param l
void list_init(list *l) {
    l->head = NULL;
}

/// @brief free a linked list
/// @param l 
void list_free(list *l) {
    node *temp = l->head;
    while (temp != NULL) {
        node *next = temp->next;
        free(temp);
        temp = next;
    }

    l->head = NULL;
    free(l);
}

/// @brief Check if a linked list is empty
/// @param l
int list_empty(list *l) {
    return l->head == NULL;
}

/// @brief Get the last node of a linked list
/// @param l 
/// @return 
node *list_top(list *l) {
    if(list_empty(l)) return NULL;

    node *temp = l->head;

    // go to end of list
    while(temp->next != NULL) {
        temp = temp->next;
    }

    return temp;
}

/// @brief Pop a node from the list
/// @param l 
/// @return 
node *list_pop(list *l) {
    if(list_empty(l)) return NULL;

    node *temp = l->head;
    node *prev = NULL;

    // go to end of list
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    // remove last node
    if (prev != NULL) {
        prev->next = NULL;
    } else {
        l->head = NULL;
    }

    return temp;
}

/// @brief Push a node to the end of a linked list
/// @param l 
/// @param node 
void list_push(list *l, node *n) {
    if (list_empty(l)) {
        l->head = n;
    } else {
        node *temp = top(l);
        temp->next = n;
    }
}

/// @brief Insert a node after a node
/// @param n
/// @param new_n
void list_insert_after(node *n, node *new_n) {
    new_n->next = n->next;
    n->next = new_n;
}

/// @brief Insert a node to the beginning of a linked list
/// @param l 
/// @param n 
void list_insert_beginning(list *l, node *n) {
    n->next = l->head;
    l->head = n;
}

/// @brief Remove the node after this node
/// @param n 
void list_remove_after(node *n) {
    if (n->next != NULL) {
        node *temp = n->next;
        n->next = temp->next;
        free(temp);
    }
}

/// @brief Remove the head node of a linked list
/// @param l
void list_remove_beginning(list *l) {
    if (l->head != NULL) {
        node *temp = l->head;
        l->head = temp->next;
        free(temp);
    }
}

/// @brief Find a node in a linked list
/// @param l
/// @param x
/// @return
node *list_find(list *l, list_type x) {
    node *temp = l->head;

    while (temp != NULL) {
        if (temp->data == x) {
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}

/// @brief Convert a linked list to a string
/// @param l 
/// @return 
char *to_string(list *l) {
    char *str = (char *)malloc(sizeof(char) * 100);
    str[0] = '\0';

    node *temp = l->head;

    while (temp != NULL) {
        char *temp_str = (char *)malloc(sizeof(char) * 100);
        sprintf(temp_str, "%d", temp->data);
        strcat(str, temp_str);
        strcat(str, " ");
        temp = temp->next;
    }

    return str;
}