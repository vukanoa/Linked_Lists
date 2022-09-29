#include <stdio.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

void put(int data);
int erase(int data);
int find(int data);
void print_list();

