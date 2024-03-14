#include <stdio.h>
#include "Node.h"
#include <stdlib.h>


// Initialize a node to NULL
void init_node(Node **node) {
   *node = NULL;
}

// Create a new node with the given information
void get_node(Node **node, list_info x) {
   *node = (Node *)malloc(sizeof(Node));
   if (*node == NULL) {
       printf("Space overflow\n");
   } else {
       (*node)->next = NULL;
       (*node)->info = x;
   }
}

// Insert a new node at the head of the list
void insert_to_head(Node **head, list_info x) {
   Node *new_head;
   get_node(&new_head, x);
   if (new_head != NULL) {
       if (*head == NULL) {
           new_head->next = new_head;  // Circular link for the only node
       } else {
           new_head->next = (*head)->next;
           (*head)->next = new_head;
       }
       *head = new_head;
   }
}

// Insert a new node after a given position in the list
void insert_after(Node *pos, list_info x) {
   if (pos == NULL) {
       printf("Invalid position\n");
       return;
   }
   Node *new_node;
   get_node(&new_node, x);
   if (new_node != NULL) {
       new_node->next = pos->next;
       pos->next = new_node;
   }
}

// Function to delete the head node and return its information
list_info delete_head(Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return -1; // Assuming -1 is an invalid value, adjust accordingly
    }

    list_info data = (*head)->next->info;
    Node *temp = (*head)->next;

    if (temp == (*head)->next) { // Check if only one node exists
        free(*head);
        *head = NULL;
    } else {
        (*head)->next = temp->next;
        free(temp);
    }

    return data;
}

// Function to insert a node with information 'x' at the end of the list
void insert_to_end(Node **head, list_info x) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->info = x;

    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    if (*head == NULL) {
        new_node->next = new_node; // Circular link for the only node
        *head = new_node;
    } else {
        Node *last = (*head)->next;
        while (last->next != (*head)) {
            last = last->next;
        }
        last->next = new_node;
        new_node->next = (*head)->next;
        (*head) = new_node;
    }
}

// Function to check if the list is empty
int is_empty(Node *head) {
    return head == NULL;
}

// Function to print the list
void print_list(Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *current = head->next;
    do {
        printf("%d -> ", current->info);
        current = current->next;
    } while (current != head->next);
    printf("\n");
}

// Function to free the memory allocated for all nodes in the list
void free_list(Node **head) {
    if (*head == NULL) {
        return;
    }

    Node *current = (*head)->next;
    while (current != *head) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(*head);
    *head = NULL;
}


// Function prototypes for helper functions (implementations not provided)
void insert_to_head(Node **list, int value);
void insert_after(Node *node, int value);

void create_list(Node **list) {

    int x;
    printf("Enter a number (-1 to stop): ");
    scanf("%d", &x);

    while (x != -1) {
        insert_to_head(list, x);
        printf("Enter a number (-1 to stop): ");
        scanf("%d", &x);
    }
}

void del_max(Node **list) {

    if (*list == NULL || (*list)->next == *list) {
        // Handle empty list or list with only one node
        free(*list);
        *list = NULL;
        return;
    }

    Node *pos = *list;
    Node *del = *list;
    Node *prev = NULL;
    int max = pos->info;

    // Find the node with the maximum value
    do {
        if (pos->info > max) {
            max = pos->info;
            del = pos;
        }
        prev = pos;
        pos = pos->next;
    } while (pos != *list);

    // If the maximum value is in the first node, update the list pointer
    if (del == *list) {
        *list = del->next;
    }

    // Remove the node with the maximum value
    prev->next = del->next;
    free(del);
}

void add_sum(Node **list) {

    Node *pos = *list;

    do {
        int x = pos->info + pos->next->info;
        insert_after(pos, x);
        pos = pos->next->next; // Skip the newly added node
    } while (pos != *list);
}

void reverse(Node **list)
{
    if (*list == (*list)->next)
    {
        return;
    }
    list_info info = deletehead(list);
    reverse(list);
    InsertToEnd(list, info);
}

void reverse_and_skip(Node **list)
{
    reverse(list);
    Node *pos = *list;
    do
    {
        pos->next = pos->next->next;
        pos = pos->next;
    } while (pos != *list);
}

void divide_list(Node **list, Node **even, Node **odd)
{
    Node *pos = *list;
    Node *posOdd = *even;
    Node *posEven = *odd;
    Node *lastOdd = posOdd;
    Node *lastEven = posEven;
    do
    {
        if (pos->info % 2 == 0)
        {
            if (posEven == NULL)
            {
                posEven = pos;
                lastEven = posEven;
            }
            else
            {
                lastEven->next = pos;
                lastEven = lastEven->next;
            }
            pos = pos->next;
            lastEven->next = posEven;
        }
        else
        {
            if (posOdd == NULL)
            {
                posOdd = pos;
                lastOdd = posOdd;
            }
            else
            {
                lastOdd->next = pos;
                lastOdd = lastOdd->next;
            }
            pos = pos->next;
            lastOdd->next = posOdd;
        }
    } while (pos != *list);
    *even = posEven;
    *odd = posOdd;
}