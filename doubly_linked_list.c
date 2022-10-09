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


int
d_erase(struct d_Node** head, int data, struct d_Node** tail)
{
	if ((*head) == NULL)
	{
		printf("\n\tUnable to delete! Doubly Linked List is Empty.\n\n");
		return -1;
	}

	if ((*head)->next == NULL) // Only one Node in the List
	{
		if ((*head)->data == data)
		{
			free(*head);
			return 0;
		}

		return -1;
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

				return 0;
			}
			tmp = tmp->next;
		}
	}
	return -1;
}
