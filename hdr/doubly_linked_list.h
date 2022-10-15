#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>

// 'd' for Doubly (Linked List)
struct d_Node{
	int data;
	struct d_Node* next;
	struct d_Node* prev;
};

// List functions
void d_push	(struct d_Node** head, int data, struct d_Node** tail);
void d_put	(struct d_Node** head, int data, struct d_Node** tail);

void d_erase(struct d_Node** head, int data, struct d_Node** tail);
void d_find	(struct d_Node*  head, int data);

void d_print_list	(struct d_Node* head);
void d_print_reverse(struct d_Node* tail);
void d_generate_list(struct d_Node** head, struct d_Node** tail);
void d_destroy_list	(struct d_Node** head);

void			d_merge_sort_old(struct d_Node** head);
struct d_Node*	d_merge_sort_new(struct d_Node*  head);
void			d_quick_sort	(struct d_Node*  front, struct d_Node* right);
void			d_quick_sort_new(struct d_Node** head, struct d_Node** front, struct d_Node** right, struct d_Node** tail);

// Util functions
struct d_Node*	d_sorted_merge	(struct d_Node* a,     struct d_Node* b);
struct d_Node*	d_mid_node		(struct d_Node* head);
struct d_Node*	d_partition		(struct d_Node* front, struct d_Node* right);
struct d_Node*	d_partition_new	(struct d_Node** head, struct d_Node** front, struct d_Node** right, struct d_Node** tail);
void			d_swap			(struct d_Node* low,   struct d_Node* high);
void			swap_pointers	(struct d_Node** head, struct d_Node** left, struct d_Node** right, struct d_Node** tail);

#endif // DOUBLY_LINKED_LIST_H
