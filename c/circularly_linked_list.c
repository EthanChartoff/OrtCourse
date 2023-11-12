#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "circularly_linked_list.h"

void list_init(Node **list) {
    *list = NULL;
}

void list_insert_after(Node *node, list_type x) {
    Node *new_node;

    new_node = (Node *) malloc(sizeof(Node));
    if(new_node != NULL) {
        new_node->data = x;
        new_node->next = node->next;
        node->next = new_node;
    }
}

void list_insert_tail(Node **list, list_type x) {
    Node *new_node;

    new_node = (Node *) malloc(sizeof(Node));
    if(new_node != NULL) {
        new_node->data = x;
        if((*list) != NULL) {
            new_node->next = (*list)->next;
            (*list)->next = new_node;
            (*list) = new_node;
        } else {
            new_node->next = new_node;
            (*list) = new_node;
        }
    }
}

void list_insert_head(Node **list, list_type x) {
    Node *new_node;

    new_node = (Node *) malloc(sizeof(Node));
    if(new_node != NULL) {
        new_node->data = x;
        if((*list) != NULL) {
            new_node->next = (*list)->next;
            (*list)->next = new_node;
        } else {
            new_node->next = new_node;
            (*list) = new_node;
        }
    }
}

list_type list_delete_after(Node *n) {
    list_type data;
    if(n == NULL) {
        return -1;
    } else if(n->next == n) {
        data = n->data;
        free(n);
    } else {
        Node* tmp = n->next;
        n->next = n->next->next;
        free(tmp);
    }
    return data;
}

list_type list_delete_tail(Node **list) {
    list_type data;

    if(*list == NULL) {
        return -1;
    } else {
        Node *curr = *list;
        Node *prev;

        while(curr->next != *list) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = (*list)->next;
        data = (*list)->data;
        free(*list);
        (*list) = prev;
    }
    return data;
}

list_type list_delete_head(Node **list) {
    list_type data;
    if(*list == NULL) {
        return -1;
    } else {
        data = (*list)->next->data;
        (*list)->next = (*list)->next->next;
    }
    return data;
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

Node* sum_big_num(Node **n1, Node **n2) {
    Node *sum;
    Node *num1, *num2;
    unsigned int curr_sum, carry;

    list_init(&sum);
    list_insert_head(&sum, -1);
    num1 = (*n1)->next->next;
    num2 = (*n2)->next->next;
    carry = 0;

    while(num1->data != -1 || num2->data != -1) {
        if(num1->data != -1 && num2->data != -1) {
            curr_sum = num1->data + num2->data + carry;
            if(curr_sum > 9999) {
                carry = 1;
                curr_sum = (curr_sum % 10000);
            } else {
                carry = 0;
            }
            list_insert_after(sum, curr_sum);
            num1 = num1->next;
            num2 = num2->next;
        } else if(num1->data == -1) {
            list_insert_after(sum, num2->data + carry);
            num2 = num2->next;
            carry = 0;
        } else {
            list_insert_after(sum, num1->data + carry);
            num1 = num1->next;
            carry = 0;
        }
        sum = sum->next;
    }
    if(carry > 0) {
        list_insert_tail(&sum, carry);
    }
    return sum;
}