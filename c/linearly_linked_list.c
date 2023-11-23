#include <stdlib.h>
#include <stdio.h>

#include "linearly_linked_list.h"

/// @brief initialize list.
/// @param n 
void list_init(Node **n) {
    *n = NULL;
}

/// @brief insert a new element to the beginning of the list. 
/// @param head 
/// @param element 
void list_insert_to_head(Node **head, list_type element) {
    Node *new_Node;

    new_Node = (Node*) malloc(sizeof(Node));
    if(new_Node != NULL) {
        new_Node->data = element;
        new_Node->next = *head; 
        *head = new_Node;
    } 
}

/// @brief insert a new element to the list after a certain Node.
/// @param n 
/// @param element 
void list_insert_after(Node *n, list_type element) {
    Node *new_Node;
    
    new_Node = (Node*) malloc(sizeof(Node));
    if(new_Node != NULL) {
        new_Node->data = element;
        new_Node->next = n->next;
        n->next = new_Node;
    }
}

/// @brief insert a new element to the end of the list.
/// @param n 
/// @param element 
void list_insert_end(Node *n, list_type element) {
    Node *new_Node;

    new_Node = (Node*) malloc(sizeof(Node));
    if(new_Node != NULL) {
        new_Node->data = element;
        new_Node->next = NULL;
        if(n != NULL) {
            while(n->next != NULL)
                n = n->next;
            n->next = new_Node;   
        } else {
            n = new_Node;
        }
    }
}

/// @brief link to lists together into a new list. 
/// @param start 
/// @param end 
/// @param new_Node 
void list_link(Node *start, Node *end, Node **new_Node) {
    (*new_Node)->next = start;
    while(start->next != NULL)
        start = start->next;
    start->next = end;
}

/// @brief create a new list using user inputs.
/// @return head to new list.
Node* list_create() {
    Node *head, *last;
    int n;
    list_init(&head);

    while(scanf("%d", &n) == 1) {
        if(head == NULL) {
            list_insert_to_head(&head, n);
            last = head;
        } else {
            list_insert_after(last, n);
            last = last->next;
        } 
    }
    return head;
}

void list_flip(Node **n) {
    Node *head;
    list_init(&head);

    while(*n != NULL) {
        list_insert_to_head(&head, (*n)->data);
        *n = (*n)->next;
    }
    
    *n = head;
}

void list_print(Node *n) {
    while(n != NULL) {
        printf("%d->", n->data);
        n = n->next;
    }
}

// scan nums for 2 empty lists, put the nums into each list sorted.
void list_scan_and_sort_2(Node **n1, Node **n2) {
    int i, n, flag;
    Node *tmp;

    while(scanf("%d", &n) == 1) {
        tmp = *n1;
        flag = 1;
        if(*n1 == NULL) {
            list_insert_to_head(n1, n);
        }
        while(flag && tmp != NULL) {
            if(tmp->next == NULL) {
                if(n < tmp->data) {
                    list_insert_after(tmp, n);
                } else {
                    list_insert_to_head(n1, n);
                }
                flag = 0;
            } else if(n < tmp->data && n >= tmp->next->data) {
                list_insert_after(tmp, n);
                flag = 0;
            }
            tmp = tmp->next;
        } 
    }
    getchar();

    while(scanf("%d", &n) == 1) {
        tmp = *n2;
        flag = 1;
        if(*n2 == NULL) {
            list_insert_to_head(n2, n);
        }
        while(flag && tmp != NULL) {
            if(tmp->next == NULL) {
                if(n < tmp->data) {
                    list_insert_after(tmp, n);
                } else {
                    list_insert_to_head(n2, n);
                }
                flag = 0;
            } else if(n < tmp->data && n >= tmp->next->data) {
                list_insert_after(tmp, n);
                flag = 0;
            }
            tmp = tmp->next;
        } 
    }
}






