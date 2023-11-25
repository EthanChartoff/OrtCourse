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

// delete the node after the given node 
list_type list_delete_after(Node *n) {
    list_type data;
    if(n == NULL) {
        return -1;
    } else {
        Node* tmp = n->next;
        data = tmp->data;
        n->next = n->next->next;
        free(tmp);
    }
    return data;
}

/// @brief link to lists together into a new list. 
/// @param start 
/// @param end 
/// @param new_Node 
void list_link(Node *start, Node *end, Node **new_Node) {
    (*new_Node) = start;
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

// a. scan nums for 2 empty lists, put the nums into each list sorted.
// b. chack if the two lists are equel.
// c. merge the two lists and sort them
void list_scan_and_sort_2(Node **n1, Node **n2) {
    int i, n, flag;
    Node *tmp1, *tmp2, *tmp3;

    // a
    while(scanf("%d", &n) == 1) {
        tmp1 = *n1;
        flag = 1;
        if(*n1 == NULL) {
            list_insert_to_head(n1, n);
        }
        while(flag && tmp1 != NULL) {
            if(tmp1->next == NULL) {
                if(n < tmp1->data) {
                    list_insert_after(tmp1, n);
                } else {
                    list_insert_to_head(n1, n);
                }
                flag = 0;
            } else if(n < tmp1->data && n >= tmp1->next->data) {
                list_insert_after(tmp1, n);
                flag = 0;
            }
            tmp1 = tmp1->next;
        } 
    }

    getchar();
    
    while(scanf("%d", &n) == 1) {
        tmp2 = *n2;
        flag = 1;
        if(*n2 == NULL) {
            list_insert_to_head(n2, n);
        }
        while(flag && tmp2 != NULL) {
            if(tmp2->next == NULL) {
                if(n < tmp2->data) {
                    list_insert_after(tmp2, n);
                } else {
                    list_insert_to_head(n2, n);
                }
                flag = 0;
            } else if(n < tmp2->data && n >= tmp2->next->data) {
                list_insert_after(tmp2, n);
                flag = 0;
            }
            tmp2 = tmp2->next;
        } 
    }

    // b
    flag = 1;
    tmp1 = *n1;
    tmp2 = *n2;
    while(tmp1 != NULL && tmp2 != NULL && flag) {
        flag = (tmp1->data == tmp2->data) && tmp1 != NULL && tmp2 != NULL; 
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    printf("%s\n", flag ? "lists are equel" : "lists are not equel");

    // c
    tmp1 = *n1;
    tmp2 = *n2;
    if((*n1)->data < (*n2)->data) {
        list_insert_to_head(n1, (*n2)->data);
        tmp2 = tmp2->next;
    }
    while(tmp2 != NULL) {
        if(tmp1->next->data <= tmp2->data || tmp1->next == NULL) {
            list_insert_after(tmp1, tmp2->data);
            tmp2 = tmp2->next;
        } else {
            tmp1 = tmp1->next;
        }
    }
}