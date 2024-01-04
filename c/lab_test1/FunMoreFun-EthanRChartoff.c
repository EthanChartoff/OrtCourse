#include "List.h"
#include <stddef.h>
#include <stdio.h> 

// list: has at least 3 elements
// res: empty
int Fun(Node **list, Node **res) {
    // Initialize pointers and counter
    Node *curr = *list, *prev = NULL, *prev2 = NULL, *prev_odd = NULL, *prev_even = NULL, *odd = NULL, *even = NULL, *head = NULL;
    int counter = 0;

    while (curr != NULL) {
        // Check if curr node breaks ascending order
        if (prev != NULL && curr->info < prev->info) {
            counter++;
            // if it is first node that breaks order
            if (prev2 == NULL) {
                head = prev;
                if (prev->info % 2 == 0)
                    even = prev;
                else
                {
                    odd = prev;
                }
            } else {
                // Check if the previous node is even
                if (prev->info % 2 == 0) {
                    even = prev;
                    prev_even = prev2;
                }
                // if not
                else {
                    odd = prev;
                    prev_odd = prev2;
                }
            }
        }
        prev2 = prev;
        prev = curr;
        curr = curr->next;
    }

    // Check if the list is invalid
    if (counter != 2 || odd == NULL || even == NULL) {
        printf("Bad List\n");
        return 1;
    }

    // if (head)
    //     (*list) = head->next;
    // Remove odd and even nodes from the original list
    if (prev_even != NULL) {
        if (head && head == prev_even) // If the head is even
            *list = even->next;
        else {
            // check if prev even is odd
            if (prev_even == odd) {
                prev_odd->next = even->next;
                prev_odd = NULL;
            }
            else
                prev_even->next = even->next; 
        }
    }
    if (prev_odd != NULL) {
        if (head && head == prev_odd) // If the head is odd
            *list = odd->next;
        else {
            if (prev_odd == even)
                prev_even->next = odd->next;
            else
                prev_odd->next = odd->next; // If the head is even
        }
    }

    // Add odd and even nodes to the res list
    odd->next = even;
    even->next = NULL;
    *res = odd;

    return 0;
}

void MoreFun(Node **list, Node **res) {
    Node *tmp_list, *tmp_res;
    int n1 = (*res)->info; 
    int n2 = (*res)->next->info;

    // insert sub
    InsertToHead(res, n2 - n1);
    tmp_list = *list;
    tmp_res = *res;

    // insert avg
    *res = (*res)->next;
    InsertAfter(*res, (n2 + n1)/2);

    // insert add
    *res = (*res)->next;
    *res = (*res)->next;
    InsertAfter(*res, n2 + n1);

    // concat res to list
    while((*list)->next)
        (*list) = (*list)->next;
    (*list)->next = tmp_res;
    
    *list = tmp_list;
    *res = tmp_res; 
} 

// int main() {
//     // tests
//     Node *head, *res, *tmp;
//     int funFlag;

//     // init list
//     Init(&head);
//     Init(&res);

//     InsertToHead(&head, 9);
//     tmp = head;
//     InsertAfter(head, 8);
//     head = head->next;
//     InsertAfter(head, 7);
//     head = head->next;
//     InsertAfter(head, 6);
//     head = head->next;
//     InsertAfter(head, 11);
//     head = head->next;
//     InsertAfter(head, 12);

//     // 1. print list
//     // PrintList(tmp);
//     // printf("\n");

//     // 2. call fun
//     funFlag = Fun(&tmp, &res);

//     // 3. print list and res
//     // printf("%s", funFlag ? "good list\n" : "bad list\n");
//     // PrintList(tmp);
//     // printf("\n");
//     // PrintList(res);
//     // printf("\n");

//     // 4. if good list
//     if(funFlag) {
//         // 5. call moreFun with same lists
//         MoreFun(&tmp, &res);

//         // 6. print lists
//         // PrintList(tmp);
//         // printf("\n");
//         // PrintList(res);
//         // printf("\n");
//     }

//     return 0;
// }