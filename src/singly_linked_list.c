#include <stdlib.h>
#include <time.h>
#include "singly_linked_list.h"

void
push(struct Node** head, int data, struct Node** tail)
{
	if ((*head) == NULL)
	{
		(*head) = (struct Node*) malloc(sizeof(struct Node));
		(*head)->data = data;
		(*head)->next = NULL;

		(*tail) = (*head);
	}
	else
	{
		struct Node* tmp = (struct Node*) malloc(sizeof(struct Node));
		tmp->data = data;
		tmp->next = (*head);

		(*head) = tmp;
	}

	printf("\n\tElement %d has been pushed to List\n\n", data);
}


void
put(struct Node** head, int data, struct Node** tail)
{
   if ((*head) == NULL)
   {
       (*head) = (struct Node*) malloc(sizeof(struct Node));
       (*head)->data = data;
       (*head)->next = NULL;

	   (*tail) = (*head);
   }
   else
   {
       struct Node* tmp = (struct Node*) malloc(sizeof(struct Node));
       tmp->data = data;
       tmp->next = NULL;

       (*tail)->next = tmp;
       (*tail) = tmp;
   }

   printf("\n\tElement %d has been put to List\n\n", data);
}


void
insert(struct Node** head, int data)
{
	struct Node* new_element = (struct Node*) malloc(sizeof(struct Node));
	new_element->data = data;
	new_element->next = NULL;

	if ((*head) == NULL || data < (*head)->data)
	{
		new_element->next = (*head);
		(*head) = new_element;
	}
	else
	{
		struct Node* cur = (*head);
		while (cur->next != NULL && cur->next->data < data)
			cur = cur->next;

		new_element->next = cur->next;
		cur->next = new_element;
	}
	printf("\n\tElement %d has been properly inserted to List!\n\n", data);
}


int
erase(struct Node** head, int data, struct Node** tail)
{
	printf("\n\t");

	if ((*head) == NULL)
	{
		printf("Unable to delete! List is empty.\n\n");
		return -1;
	}

	struct Node* prev = NULL;
	struct Node* cur = ((*head));
	while (cur)
	{
		if (cur->data == data)
		{
			if (cur == ((*head)))
				((*head)) = cur->next;
			else // Ovde mora da se obradi i tail
			{
				if (cur == (*tail))
					(*tail) = prev;

				prev->next = cur->next;
			}

			free(cur);

			printf("Element %d has been successfully removed!", data);
			printf("\n\n");

			return 0;
		}

		prev = cur;
		cur = cur->next;
	}

	printf("Element %d doesn't exist in the list!", data);
	printf("\n\n");

	return -1;
}


int
find(struct Node* head, int data)
{
    struct Node* cur = head;

    while (cur)
    {
        if (cur->data == data)
            return 1;

        cur = cur->next;
    }

    return 0;
}


void
print_list(struct Node* head)
{
    struct Node* cur = head;
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
reverse_list(struct Node** head)
{
	printf("\n\tList has been reversed successfully!\n\n");

	printf("\tPrevious order:");
	print_list(*head);

	struct Node* p, *q, *r;
	p = NULL;
	q = (*head);
	r = (*head)->next;

	while (r != NULL)
	{
		q->next = p;
		p = q;
		q = r;
		r = q->next;
		q->next = p;
	}
	(*head) = q;

	printf("\tCurrent order:");
	print_list(*head);
}


void
generate_list(struct Node** head, struct Node** tail)
{
	int size = -1;
	struct Node* tmp = NULL;

	if ((*head) != NULL)
	{
		printf("   !!!   WARNING: Another list already exists. Destroy it to prevent memory leak!\n: ");
		destroy_list(head);
	}
	srand(time(NULL));

	for(;;)
	{
		printf("How many elements would you like to have?\n: ");
		scanf("%d", &size);

		if (size < 0)
			printf("\n\tUnable to make a list of size \"%d\". Try again.\n\n: ", size);
		else if (size == 0)
		{
			printf("\n\tOperation \"Generate random List\" was canceled.\n\n: ");
			return;
		}
		else
			break;
	}

	for (int i = 0; i < size; i++)
	{
		tmp = (struct Node*) malloc(sizeof(struct Node));
		tmp->data = rand() % 100;
		tmp->next = NULL;

		if ((*head) == NULL)
			(*head) = (*tail) = tmp;
		else
		{
			tmp->next = (*head);
			(*head) = tmp;
		}
	}

	printf("\n\tA list has been successfully generated!\n\n");
}


void
destroy_list(struct Node** head)
{
	if ((*head) == NULL)
	{
		printf("\n\tUnable to destroy a non-existant List.\n\n");
		return;
	}

	struct Node* tmp = NULL;

	int destroy;
	printf("Are you sure you want to DESTROY a list? [yes - 1, no - 0]\n: ");
	scanf("%d", &destroy);

	if (!destroy)
	{
		printf("\n\tOperation \"Destroy a list\" was canceled.\n\n");
		return;
	}
	
	while ((*head))
	{
		tmp = (*head);
		(*head) = (*head)->next;
		free(tmp);
	}

	printf("\n\tA list has been destroyed!\n\n");
}


void
selection_sort(struct Node* head)
{
	if (head == NULL || head->next == NULL)
	{
		printf("\n\tThere's nothing to sort!\n\n");
		return;
	}

	// Selection sort O(n^2)
	struct Node *i, *j;
	int tmp;

	for (i = head; i->next != NULL; i = i->next)
	{
		for (j = i->next; j != NULL; j = j->next)
		{
			if (i->data > j->data)
			{
				tmp = i->data;
				i->data = j->data;
				j->data = tmp;
			}
		}
	}

	printf("\n\tA list has been successfully Selection-sorted!\n\n");
}


void
bubble_sort(struct Node* head)
{
	if (head == NULL || head->next == NULL)
	{
		printf("\n\tThere's nothing to sort!\n\n");
		return;
	}

	// Bubble sort O(n^2)
	int swapped;
	struct Node* cur;
	struct Node* last_sorted = NULL;

	if (head == NULL)
		return;

	do
	{
		swapped = 0;
		cur = head;

		while (cur->next != last_sorted)
		{
			if (cur->data > cur->next->data)
			{
				swap(cur, cur->next);
				swapped = 1;
			}
			cur = cur->next;
		}
		last_sorted = cur;
	} while(swapped);

	printf("\n\tA list has been successfully Bubble-sorted!\n\n");
}


void
merge_sort(struct Node** head) // 5 2 4
{
	// O(n * logn)
	if ((*head) == NULL || (*head)->next == NULL)
		return;

	// Split
	struct Node* mid = mid_node(*head);

	struct Node* a = (*head);
	struct Node* b = mid->next;

	// Split at the mid
	mid->next = NULL;

	// Sort left and right half recursively
	merge_sort(&a);
	merge_sort(&b);

	(*head) = sorted_merge(a, b);
}


void
swap(struct Node *a, struct Node *b)
{
	int tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}


struct Node*
sorted_merge(struct Node* a, struct Node* b)
{
	struct Node* ret_head = NULL;
	struct Node* tail = NULL;

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
	while(a != NULL && b != NULL)
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

struct Node*
mid_node(struct Node* head)
{
	struct Node* slow = head;
	struct Node* fast = head->next;

	if (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

void
quick_sort(struct Node* head, struct Node* tail)
{
	if (head == NULL || tail == NULL || head == tail)
		return;

	struct Node* pivot = partition(head, tail);
	quick_sort(head, pivot);
	quick_sort(pivot->next, tail);
}

// 2 8 7

struct Node*
partition(struct Node* left, struct Node* right)
{
	struct Node* front = NULL;
	struct Node* first_node = left;

	while(left != right)
	{
		if (left->data < right->data)
		{
			front = front ? front->next : first_node;

			if (front != left)
				swap(front, left);
		}
		left = left->next;
	}
	swap(front ? front->next : first_node, right);

	return front ? front : first_node;
}


struct Node*
kth_to_last(struct Node* head, int k)
{
	if (head == NULL || k < 0)
		return NULL;

	if (k == 0)
	{
		if (head->next == NULL)
			return head;

		while (head->next != NULL)
			head = head->next;

		return head;
	}

	struct Node* cur  = head;
	struct Node* iter = head;

	while (k-- > 0)
	{
		if (iter == NULL)
			return NULL;

		iter=iter->next;
	}

	if (iter == NULL)
		return NULL;

	while (iter->next != NULL)
	{
		cur  = cur->next;
		iter = iter->next;
	}
	return cur;
}


void
the_runner_technique(struct Node* head)
{
	if (head == NULL)
		return;
	
	if (head->next->next == NULL) // We're told there are even number of nodes
		return; //Already alternating

	struct Node* slow = head;
	struct Node* fast = head->next;
	struct Node* tmp  = NULL;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	fast = head;
	while (slow->next->next != NULL)
	{
		tmp = fast->next;
		fast->next = slow->next;
		slow->next = slow->next->next;
		
		fast->next->next = tmp;
		fast = fast->next->next;
	}
}


void
remove_duplicates(struct Node* head)
{
	// Base case
	if (head == NULL || head->next == NULL)
		return;
	
	struct Node* dup = head;
	struct Node* tmp = NULL; // For freeing to prevent Memory Leak

	while(head)
	{
		while (dup->next)
		{
			if (dup->next->data == head->data)
			{
				tmp = dup->next;
				dup->next = dup->next->next;

				free(tmp);
			}
			else
				dup = dup->next;
		}
		head = head->next;
		dup = head;
	}
}
