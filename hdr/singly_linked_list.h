#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdio.h>

struct Node{
    int data;
    struct Node* next;
};

// Singly Linked List functions
void push   (struct Node** head, int data, struct Node** tail);
void put    (struct Node** head, int data, struct Node** tail);
void insert (struct Node** head, int data);

int erase	(struct Node** head, int data, struct Node** tail);
int find	(struct Node*  head, int data);

void print_list		(struct Node*  head);
void reverse_list	(struct Node** head);	
void generate_list	(struct Node** head, struct Node** tail);
void destroy_list	(struct Node** head);

void selection_sort	(struct Node*  head);
void bubble_sort	(struct Node*  head);
void merge_sort		(struct Node** head);
void quick_sort		(struct Node*  head, struct Node* tail);

// Util functions
void swap(struct Node *a, struct Node *b);
struct Node* sorted_merge	(struct Node* a, struct Node* b);
struct Node* mid_node		(struct Node* head);
struct Node* partition		(struct Node* left, struct Node* right);

// List Problems
struct Node* kth_to_last			(struct Node* head, int k);
void		 the_runner_technique	(struct Node* head);
void		 remove_duplicates		(struct Node* head);
void		 delete_middle_node		(struct Node* mid);
struct Node* separate_around_value	(struct Node* head, int x);

#endif // SINGLY_LINKED_LIST_H
