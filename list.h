#include <stdio.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

// List functions
void push   (Node** head, int data, Node** tail);
void put    (Node** head, int data, Node** tail);
void insert (Node** head, int data);

int erase	(Node** head, int data);
int find	(Node*  head, int data);

void print_list		(Node*  head);
void reverse_list	(Node** head);	
void generate_list	(Node** head, Node** tail);
void destroy_list	(Node** head);

void selection_sort (Node* head);
void bubble_sort	(Node* head);

// Util function
void swap();
Node* sorted_merge(Node* a, Node* b);
