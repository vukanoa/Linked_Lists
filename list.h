#include <stdio.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

void push(int data);
void put(int data);
int erase(int data);
int find(int data);
void print_list();
void reverse_list();	
void generate_list();
