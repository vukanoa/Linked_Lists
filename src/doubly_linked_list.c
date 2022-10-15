#include <stdlib.h>
#include <time.h>
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
	printf("\n\t");

	if (head == NULL)
		printf("Empty");

	while (head)
	{
		printf("%d ", head->data);

		head = head->next;
	}
	printf("\n\n");
}


void
d_print_reverse(struct d_Node* tail)
{
	printf("\n\t");

	if (tail == NULL)
		printf("Empty");

	while (tail)
	{
		printf("%d ", tail->data);

		tail = tail->prev;
	}
	printf("\n\n");
}


void
d_generate_list(struct d_Node** head, struct d_Node** tail)
{
	int size;
	struct d_Node* tmp = NULL;

	if ((*head) != NULL)
	{
		printf("   !!!   WARNING: Another Doubly Linked List already exists. Destroy it to prevent memory leak!");
		d_destroy_list(head);
	}
	srand(time(NULL));

	for(;;)
	{
		printf("How many elements would you like to have?\n: ");
		scanf("%d", &size);

		if (size < 0)
			printf("\n\tUnable to make a list of size\"%d\". Try again.\n\n: ", size);
		else if (size == 0)
		{
			printf("\n\tOperation \"Generate random Doubly Linked List\" was canceleed.\n\n");
			return;
		}
		else
			break;
	}

	for (int i = 0; i < size; i++)
	{
		tmp = (struct d_Node*) malloc(sizeof(struct d_Node));
		tmp->data = rand() % 100;
		tmp->next = NULL;
		tmp->prev = NULL;

		if ((*head) == NULL)
			(*head) = (*tail) = tmp;
		else
		{
			tmp->next = (*head);
			(*head)->prev = tmp;
			(*head) = tmp;
		}
	}

	printf("\n\tA Doubly Linked List has been successfully generated!\n\n");
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


void
d_merge_sort_old(struct d_Node** head)
{
	// O(n * logn)
	if ((*head) == NULL || (*head)->next == NULL)
		return;

	// Split
	struct d_Node* mid = d_mid_node((*head));

	struct d_Node* a = (*head);
	struct d_Node* b = mid->next;

	// Split at the mid
	mid->next = NULL;

	// Split left and right recursively
	d_merge_sort_old(&a);
	d_merge_sort_old(&b);

	(*head) = d_sorted_merge(a, b);
}


struct d_Node*
d_merge_sort_new(struct d_Node* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	struct d_Node* mid = d_mid_node(head);
	struct d_Node* mid_next = mid->next;

	mid->next = NULL;

	struct d_Node* a = d_merge_sort_new(head);
	struct d_Node* b = d_merge_sort_new(mid_next);

	return d_sorted_merge(a, b);
}


struct d_Node*
d_sorted_merge(struct d_Node* a, struct d_Node* b)
{
	struct d_Node* ret_head = NULL;
	struct d_Node* tail = NULL;

	// Find head with lower data
	if (a->data < b->data)
	{
		ret_head = tail = a;
		a = a->next;
	}
	else
	{
		ret_head = tail = b;
		b = b->next;
	}

	// Concatenate in ascending order
	while (a != NULL && b != NULL)
	{
		if (a->data < b->data)
		{
			tail->next = a;
			tail = tail->next;
			a = a->next;
		}
		else
		{
			tail->next = b;
			tail = tail->next;
			b = b->next;
		}
	}

	if (a == NULL)
		tail->next = b;
	else
		tail->next = a;
	
	return ret_head;
}


struct d_Node*
d_mid_node(struct d_Node* head)
{
	struct d_Node* slow = head;
	struct d_Node* fast = head->next;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}


void
d_quick_sort(struct d_Node* front, struct d_Node* right)
{
	// Base case
	if (front == NULL || right == NULL)
		return;

	if (front == right || front->prev == right || right->next == front)
		return;
	
	struct d_Node* pivot = d_partition(front, right);
	d_quick_sort(front, pivot->prev);
	d_quick_sort(pivot->next, right);
}


void // 3 2 5 1 4
d_quick_sort_new(struct d_Node** head, struct d_Node** front, struct d_Node** right, struct d_Node** tail)
{
	// Base case
	if ((*head) == NULL || (*front) == NULL || (*right) == NULL || (*tail == NULL))
		return;
	
	if ((*front) == (*right) || (*front)->prev == (*right) || (*right)->next == (*front))
		return;

	struct d_Node* pivot = d_partition_new(head, front, right, tail);
	(*front) = (*head);

	d_quick_sort_new(head, front, &pivot->prev, tail);
	d_quick_sort_new(head, &pivot->next, right, tail);
}


void
d_swap(struct d_Node* low, struct d_Node* high)
{
	int tmp = low->data;
	low->data = high->data;
	high->data = tmp;
}


struct d_Node*
d_partition(struct d_Node* front, struct d_Node* right)
{
	struct d_Node* left = front;

	while (left != right)
	{
		if (left->data < right->data)
		{
			if (front != left)
				d_swap(front, left);

			front = front->next;
		}
		left = left->next;
	}
	d_swap(front, right);

	return front;
}


// 3 2 5 1 4
// 3 2 1 4 5
struct d_Node*
d_partition_new(struct d_Node** head, struct d_Node** front, struct d_Node** right, struct d_Node** tail)
{
	struct d_Node* left = (*front);

	while (left != (*right))
	{
		if (left->data < (*right)->data)
		{
			if ((*front) != left)
				swap_pointers(head, front, &left, tail);

			(*front) = (*front)->next;
		}
		left = left->next;
	}
	swap_pointers(head, front, right, tail);

	return (*front);
}


void
swap_pointers(struct d_Node** head, struct d_Node** left, struct d_Node** right, struct d_Node** tail)
{
	struct d_Node* tmp;
	struct d_Node* tmp_left_prev  = (*left)->prev;
	struct d_Node* tmp_left_next  = (*left)->next;
	struct d_Node* tmp_right_prev = (*right)->prev;
	struct d_Node* tmp_right_next = (*right)->next;

	if ((*left)->prev == NULL && (*right)->next == NULL)
	{
		if ((*left)->next != (*right))  // 1 2 3 4 5 (1 & 5)
		{
			(*left)->prev = tmp_right_prev;
			tmp_right_prev->next = (*left);

			(*left)->next = tmp_right_next;
			(*tail) = (*left);

			(*right)->prev = tmp_left_prev;
			(*head) = (*right);

			(*right)->next = tmp_left_next;
			tmp_left_next->prev = (*right);

			tmp = (*left);
			(*left) = (*right);
			(*right) = tmp;
		}
		else  // 1 5 (1 & 5)
		{
			(*left)->prev = (*right);
			(*right)->next = (*left);

			(*left)->next = tmp_right_next;
			(*tail) = (*left);

			(*right)->prev = tmp_left_prev;
			(*head) = (*right);

			tmp = (*left);
			(*left) = (*right);
			(*right) = tmp;
		}

	}
	else if ((*left)->prev == NULL && (*right)->next != NULL)
	{
		if ((*left)->next != (*right))  // 1 2 3 4 5 (1 & 4)
		{
			// Example is 3 2 1 4 5
			// The problem is when I'm sending (3, 2, 1, 5) in this function
			// Second d_partition_new call
			// It tries to swap 3 with 1

			(*left)->prev = tmp_right_prev;
			tmp_right_prev->next = (*left);

			(*left)->next = tmp_right_next;
			//tmp_right_next->prev = (*left); WHAT THE HELL?!?!?!
			// **right which is 1 suddenly becomes 3

			(*right)->prev = tmp_left_prev;
			(*head) = (*right);

			(*right)->next = tmp_left_next;
			tmp_left_next->prev = (*right);

			// However, if I put that line down here, it suddenly works
			// WHAT. THE. HELL.
			tmp_right_next->prev = (*left);

			tmp = (*left);
			(*left) = (*right);
			(*right) = tmp;
		}
		else // 1 2 3 4 5 (1 & 2)
		{
			(*left)->prev = (*right);
			(*right)->next = (*left);

			(*left)->next = tmp_right_next;
			tmp_right_next->prev = (*left);

			(*right)->prev = tmp_left_prev;
			(*head) = (*right);

			tmp = (*left);
			(*left) = (*right);
			(*right) = tmp;
		}
	}
	else if ((*left)->prev != NULL && (*right)->next == NULL)
	{
		if ((*left)->next != (*right)) // 1 2 3 4 5 (2 & 5)
		{
			(*left)->prev = tmp_right_prev;
			tmp_right_prev->next = (*left);

			(*left)->next = tmp_right_next;
			(*tail) = (*left);

			(*right)->prev = tmp_left_prev;
			tmp_left_prev->next = (*right);

			(*right)->next = tmp_left_next;
			tmp_left_next->prev = (*right);

			tmp = (*left);
			(*left) = (*right);
			(*right) = tmp;

		}
		else // 1 2 3 4 5 (4 & 5)
		{
			(*left)->prev = (*right);
			(*right)->next = (*left);

			(*left)->next = tmp_right_next;
			(*tail) = (*left);

			(*right)->prev = tmp_left_prev;
			tmp_left_prev->next = (*right);

			tmp = (*left);
			(*left) = (*right);
			(*right) = tmp;
		}

	}
	else // 1 2 3 4 5 (2 & 4), (2 & 3) etc.
	{
		if ((*left)->next == (*right)) // 1 2 3 4 5 (2 & 3)
		{
			(*left)->prev = (*right);
			(*right)->next = (*left);

			(*left)->next = tmp_right_next;
			tmp_right_next->prev = (*left);

			(*right)->prev = tmp_left_prev;
			tmp_left_prev->next = (*right);
		}
		else // 1 2 3 4 5 (2 & 4)
		{
			(*left)->prev = tmp_right_prev;
			tmp_right_prev->next = (*left);

			(*left)->next = tmp_right_next;
			tmp_right_next->prev = (*left);

			(*right)->prev = tmp_left_prev;
			tmp_left_prev->next = (*right);

			(*right)->next = tmp_left_next;
			tmp_left_next->prev = (*right);
		}

		tmp = (*left);
		(*left) = (*right);
		(*right) = tmp;
	}
	
}
