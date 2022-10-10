#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>

// 'd' for Doubly (Linked List)
struct d_Node{
	int data;
	struct d_Node* next;
	struct d_Node* prev;
};

void d_push   (struct d_Node** head, int data, struct d_Node** tail);
void d_put    (struct d_Node** head, int data, struct d_Node** tail);
void d_insert (struct d_Node** head, int data);

int d_erase	(struct d_Node** head, int data, struct d_Node** tail);
int d_find	(struct d_Node*  head, int data);

void d_print_list		(struct d_Node* head);
void d_generate_list	(struct d_Node** head, struct d_Node** tail);
void d_destroy_list		(struct d_Node** head);

#endif // DOUBLY_LINKED_LIST_H
