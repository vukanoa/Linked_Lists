#include <stdio.h>

struct Node{
    int data;
    struct Node* next;
};

// List functions
void push   (struct Node** head, int data, struct Node** tail);
void put    (struct Node** head, int data, struct Node** tail);
void insert (struct Node** head, int data);

int erase	(struct Node** head, int data);
int find	(struct Node*  head, int data);

void print_list		(struct Node*  head);
void reverse_list	(struct Node** head);	
void generate_list	(struct Node** head, struct Node** tail);
void destroy_list	(struct Node** head);

void selection_sort (struct Node* head);
void bubble_sort	(struct Node* head);

// Util functions
void swap();
struct Node* sorted_merge(struct Node* a, struct Node* b);
