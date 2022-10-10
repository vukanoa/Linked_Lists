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
d_erase(struct d_Node** head, int data, struct d_Node** tail)
{
	if ((*head) == NULL)
	{
		printf("\n\tUnable to delete! Doubly Linked List is Empty.\n\n");
		return;
	}

	if ((*head)->next == NULL) // Only one Node in the List
	{
		if ((*head)->data == data)
		{
			free(*head);
			printf("Element %d has been successfully removed from Doubly Linked List!", data);
			return;
		}
		
		printf("Element %d does NOT exist in the Doubly Linked List!", data);
		return;
	}
	else
	{
		struct d_Node* tmp = (*head);
		while (tmp)
		{
			if (tmp->data == data)
			{
				if (tmp == (*head))
				{
					tmp->next->prev = NULL;
					(*head) = tmp->next;
					tmp->next = NULL;
					free(tmp);
				}
				else
				{
					tmp->prev->next = tmp->next;

					if (tmp == (*tail))
						(*tail) = tmp->prev;
					else
						tmp->next->prev = tmp->prev;

					tmp->next = NULL;
					tmp->prev = NULL;
					free(tmp);
				}

				printf("Element %d has been successfully removed from Doubly Linked List!", data);
				return;
			}
			tmp = tmp->next;
		}
	}
	printf("Element %d does NOT exist in the Doubly Linked List!", data);
	return;
}


void
d_find(struct d_Node* head, int data)
{
	if (head == NULL)
	{
		printf("\n\tElement %d does NOT exist in the Doubly Linked List!\n\t[A Doubly Linked List is Empty!]\n\n", data);
		return;
	}

	while (head)
	{
		if (head->data == data)
		{
			printf("\n\tElement %d does exist in the Doubly Linked List!\n\n", data);
			return;
		}
		head = head->next;
	}

	printf("\n\tElement %d does NOT exist in the Doubly Linked List!\n\n", data);
	return;
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


void
d_destroy_list(struct d_Node** head)
{
	if ((*head) == NULL)
	{
		printf("\n\tUnable to destroy a non-existant List.\n\n");
		return;
	}

	struct d_Node* tmp = NULL;

	int destroy;
	printf("\n\tAre you SURE you want to destroy a Doubly Linked list? [Yes - 1, No - 0]\n: ");
	scanf("%d", &destroy);

	if (!destroy)
	{
		printf("\n\tOperation \"Destroy a List\" was canceled.\n\n");
		return;
	}

	while ((*head))
	{
		tmp = (*head);
		(*head) = (*head)->next;
		free(tmp);
	}

	printf("\n\tA List has been destroyed!\n\n");
}
