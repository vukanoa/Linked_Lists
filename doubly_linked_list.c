#include <stdlib.h>
#include "doubly_linked_list.h"

void
d_push(struct d_Node** head, int data, struct d_Node** tail)
{
	if ((*head) == NULL)
	{
		(*head) = (struct d_Node*) malloc(sizeof(struct d_Node));
		(*head)->data = data;
		(*head)->next = NULL;
		(*head)->prev = NULL;
		(*tail) = (*head);
	}
	else
	{
		struct d_Node* tmp = (struct d_Node*) malloc(sizeof(struct d_Node));
		tmp->data = data;
		tmp->next = NULL;
		tmp->prev = NULL;

		tmp->next = (*head);
		(*head)->prev = tmp;
		(*head) = tmp;
	}

	printf("\n\tElement %d has been pushed to Doubly Linked List\n\n", data);
}


void
d_put(struct d_Node** head, int data, struct d_Node** tail)
{
	if ((*head) == NULL)
	{
		(*head) = (struct d_Node*) malloc(sizeof(struct d_Node));
		(*head)->data = data;
		(*head)->next = NULL;
		(*head)->prev = NULL;
		(*tail) = (*head);
	}
	else
	{
		struct d_Node* tmp = (struct d_Node*) malloc(sizeof(struct d_Node));
		tmp->data = data;
		tmp->next = NULL;
		tmp->prev = NULL;

		tmp->prev = (*tail);
		(*tail)->next = tmp;
		(*tail) = tmp;
	}

	printf("\n\tElement %d has been put to Doubly Linked List\n\n", data);
}


void
d_print_list(struct d_Node* head)
{
	struct d_Node* cur = head;
	printf("\n\t");

	if (head == NULL)
		printf("Empty");

	while (cur)
	{
		printf("%d ", cur->data);

		cur = cur->next;
	}
	printf("\n\n");
}
