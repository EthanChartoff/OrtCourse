#include "List.h"
#include <stdio.h>
#include <stdlib.h>

void Init(Node** head) {
	*head = NULL;
}

void getNode(Node** node, list_item x) {
	*node = (Node*)malloc(sizeof(Node));
	(*node)->info = x;
	(*node)->next = NULL;
}

void InsertAfter(Node* pos, list_item x) {
	Node* new_node;
	getNode(&new_node, x);
	if (new_node) {
		new_node->next = pos->next;
		pos->next = new_node;
	}
	else {
		printf("Could not allocate\n");
	}
}

void InsertToHead(Node** head, list_item x) {
	Node* new_node;
	getNode(&new_node, x);
	if (new_node) {
		new_node->next = *head;
		*head = new_node;
	}
	else {
		printf("Could not allocate\n");
	}
}

list_item DeleteAfter(Node* pos) {
	list_item x;
	Node* temp = pos->next;
	if (temp) {
		pos->next = temp->next;
		x = temp->info;
		free(temp);
		return x;
	}
}

list_item DeleteHead(Node** head) {
	list_item x;
	Node* temp = *head;
	x = (**head).info;
	(**head).next = (**head).next;
	free(temp);
	return x;
}

void PrintList(Node* list) {
	if (list == NULL) {
		return;
	}
	else {
		Node* pos = list;
		while (pos->next != NULL) {
			printf("%d->", pos->info);
			pos = pos->next;
		}
		printf("%d", pos->info);
	}
}