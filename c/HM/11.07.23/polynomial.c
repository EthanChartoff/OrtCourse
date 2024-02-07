#include <stdlib.h>
#include <stdio.h>

#include "polynomial.h"

/// @brief gets two proper polynomials and returns their sum. 
/// proper here means that the variable with the highest power is first, and the smallest power is last.
/// @param pol1 
/// @param pol2 
/// @return 
polynomial_node* sum(polynomial_node* pol1, polynomial_node* pol2) {
    polynomial_node *head, *last, *tmp1, *tmp2, *new_node;
    float coeff;
    int pow;

    head = NULL;
    last = head;
    tmp1 = pol1;
    tmp2 = pol2;

    while (tmp1 != NULL || tmp2 != NULL) {
        if((tmp1 != NULL && tmp2 != NULL) && tmp1->pow == tmp2->pow) {
            coeff = tmp1->coeff + tmp2->coeff;
            pow = tmp1->pow;
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        } else if(tmp1 != NULL && tmp1->pow > tmp2->pow) {
            coeff = tmp1->coeff;
            pow = tmp1->pow;
            tmp1 = tmp1->next;
        } else {
            coeff = tmp2->coeff;
            pow = tmp2->pow;
            tmp2 = tmp2->next;
        }

        new_node = (polynomial_node*) malloc(sizeof(polynomial_node));
        new_node->coeff = coeff;
        new_node->pow = pow;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            last = head;
        } else {
            last->next = new_node;
            last = new_node;
        }
    }

    return head;
}

polynomial_node* create() {
    polynomial_node *head, *last, *new_node;
    int coeff, pow;

    head = NULL;
    last = head;

    printf("Enter the coefficient and power of the polynomial: ");
    scanf("%d %d", &coeff, &pow);

    while (coeff != 0) {
        new_node = (polynomial_node*) malloc(sizeof(polynomial_node));
        new_node->coeff = coeff;
        new_node->pow = pow;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            last = head;
        } else {
            last->next = new_node;
            last = new_node;
        }

        printf("Enter the coefficient and power of the polynomial: ");
        scanf("%d %d", &coeff, &pow);
    }

    return head;
}