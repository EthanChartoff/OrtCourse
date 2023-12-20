#pragma once

typedef int list_item;

typedef struct node_type {
	list_item info;
	struct node_type* next;
} Node;

void Init(Node** head);
void getNode(Node** node, list_item x);
void InsertAfter(Node* pos, list_item x);
void InsertToHead(Node** head, list_item x);
list_item DeleteAfter(Node* pos);
list_item DeleteHead(Node** head);
void PrintList(Node* list);
