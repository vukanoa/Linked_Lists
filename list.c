#include <stdlib.h>
#include "list.h"

Node* head = NULL;
Node* tail = NULL;


void
push(int data)
{
	if (head == NULL)
	{
		head = (Node*) malloc(sizeof(Node));
		head->data = data;
		head->next = NULL;

		tail = head;
	}
	else
	{
		Node* tmp = (Node*) malloc(sizeof(Node));
		tmp->data = data;
		tmp->next = head;

		head = tmp;
	}

	printf("\n\tElement %d has been pushed to List\n\n", data);
}

void
put(int data)
{
   if (head == NULL)
   {
       head = (Node*) malloc(sizeof(Node));
       head->data = data;
       head->next = NULL;

	   tail = head;
   }
   else
   {
       Node* tmp = (Node*) malloc(sizeof(Node));
       tmp->data = data;
       tmp->next = NULL;

       if (head->next == NULL)
           head->next = tmp;

       tail->next = tmp;
       tail = tmp;
   }

   printf("\n\tElement %d has been put to List\n\n", data);
}

void
print_list()
{
    Node* cur = head;
	printf("\n\t");

	if (head == NULL)
		printf("Empty");
	
	printf("Current list:\n\t");
    while (cur)
    {
        printf("%d ", cur->data);

        cur = cur->next;
    }
    printf("\n\n");
}

