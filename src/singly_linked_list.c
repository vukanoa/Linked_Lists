#include <stdlib.h>
#include <time.h>
#include "singly_linked_list.h"

/* Singly Linked List Functions */
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

	// printf("\n\tElement %d has been pushed to List\n\n", data);
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

   // printf("\n\tElement %d has been put to List\n\n", data);
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
			else
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
		if (cur->next)
			printf("%d -> ", cur->data);
		else
			printf("%d", cur->data);

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

	struct Node* prev = NULL;
	struct Node* cur  = (*head);
	struct Node* next = NULL;

	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	(*head) = prev;

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


/* Singly Linked List Sorts */
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
merge_sort(struct Node** head)
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
quick_sort(struct Node* head, struct Node* tail)
{
	if (head == NULL || tail == NULL || head == tail)
		return;

	struct Node* pivot = partition(head, tail);
	quick_sort(head, pivot);
	quick_sort(pivot->next, tail);
}


/* Util Functions */
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


void
print_loop_list(struct Node* head)
{
	struct Node* slow = head;
	struct Node* fast = head;

	// For printing
	struct Node* out  = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			break;
	}

	// There is no Loop in the List
	if (fast == NULL || fast->next == NULL)
	{
		printf("\n\tA List is not Loop!\n\n");
		return;
	}

	// Find the Loop
	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	/* PRINTING */
	printf("Loop List:");
	printf("\n\t");

	// Printing before Loop
	while (out != slow)
	{
		printf("%d -> ", out->data);
		out = out->next;
	}

	// Print the Looping Node
	printf("|%d| -> ", out->data);

	fast = fast->next;
	// Printing the Loop
	while (slow != fast)
	{
		printf("%d -> ", fast->data);
		fast = fast->next;
	}

	// Print the Looping Node
	if (slow->next == slow)
		printf("|%d| -> |%d| -> |%d| -> ... \n\n", slow->data, slow->data, slow->data);
	else
		printf("|%d| -> %d -> %d -> ... \n\n", slow->data, slow->next->data, slow->next->next->data);
}


/* Singly Linked List Problems */
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
		return; // Already alternating

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


void
delete_middle_node(struct Node* mid)
{
	// Base case & One case where it's impossible to achieve this
	if (mid == NULL || mid->next == NULL)
		return;

	struct Node* next = mid->next;

	mid->data = next->data;
	mid->next = next->next;
	free(next);
}


struct Node*
separate_around_value(struct Node* head, int x)
{
	if (head == NULL)
		return NULL;

	struct Node* front = head;
	struct Node* rear  = head;

	while (head != NULL)
	{
		struct Node* next  = head->next;

		if (head->data < x)
		{
			head->next = front;
			front = head;
		}
		else
		{
			rear->next = head;
			rear = head;
		}
		head = next;
	}
	rear->next = NULL; // In case last element is < x

	return front;
}


/*
	===================
	=== Description ===
	===================

	You are given two non-empty linked lists representing two non-negative
	integers. The digits are stored in reverse order, and each of their nodes
	contains a single digit. Add the two numbers and return the sum as a linked
	list.

	You may assume the two numbers do not contain any leading zero, except the
	number 0 itself.

	Example 1:
	Input:  l1 = [2,4,3], l2 = [5,6,4]
	Output: [7,0,8]
	Explanation: 342 + 465 = 807.

	Example 2:
	Input:  l1 = [2,4,3], l2 = [5,6]
	Output: [7,0,4]
	Explanation: 342 + 65 = 407

	Example 3: (This illustrates the importance of carry)
	Input:  l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
	Output: [8,9,9,9,0,0,0,1]

	Example 4:
	Input:  l1 = [4,3], l2 = [5,6,4]
	Output: [9,4,4]
	Explanation: 34 + 465 = 499

	Example 5:
	Input:  l1 = [7], l2 = []
	Output: [7]

	Example 6:
	Input:  l1 = [], l2 = [5]
	Output: [5]

	Example 7:
	Input:  l1 = [], l2 = []
	Output: []

*/
/* Time  Complexity: O(n + m) */
/* Space Complexity: O(1) */
struct Node*
add_two_numbers(struct Node* l1, struct Node* l2)
{
	if (!l1 && !l2)
		return NULL;
	else if (!l1)
		return l2;
	else if (!l2)
		return l1;

	struct Node* dummy = (struct Node*) malloc(sizeof(struct Node*));
	struct Node* tail  = dummy;

	int carry = 0;
	while (l1 || l2 || carry)
	{
		int l1_data = l1 ? l1->data : 0;
		int l2_data = l2 ? l2->data : 0;

		int data = l1_data + l2_data + carry;

		carry = data / 10;
		data %= 10;

		tail->next = (struct Node*) malloc(sizeof(struct Node*));
		tail->next->data = data;
		tail = tail->next;

		l1 = l1 ? l1->next : NULL;
		l2 = l2 ? l2->next : NULL;
	}

	/* We could just end our Solution here, but that would cause Memory Leak */
	// return dummy->next;

	/* Prevent Memory Leak */
	struct Node* tmp = dummy;
	dummy = dummy->next;

	free(tmp);
	
	return dummy;
}


int
palindrome(struct Node* head)
{
	if (head == NULL || head->next == NULL)
		return 1; // Is Empty List a palindrome?

	int num_of_digits = 9; // 0 indicates non-existance
	int* array = (int*) calloc(num_of_digits, sizeof(int));
	int counter = 1;

	// O(n)
	while (head != NULL)
	{
		array[head->data] = counter++;

		if (head->next != NULL && array[head->next->data] != 0)
		{
			if (head->next->data == head->data)
				counter--;
			else
				counter -= 2;

			head = head->next;

			while (head != NULL && counter > 0)
			{
				if (array[head->data] != counter--)
					return 0;

				head = head->next;
			}
			if (counter == 0)
				return 1;
		}

		head = head->next;
	}

	return 0;
}


int
palindrome_stack(struct Node* head)
{
	int stack[10];
	int sp = -1; // Full Ascending Stack
	struct Node* slow = head;
	struct Node* fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		stack[++sp] = slow->data;
		slow = slow->next;
		fast = fast->next->next;
	}

	// Odd number of elements
	if (fast != NULL)
		slow = slow->next;

	while (slow != NULL)
	{
		if (slow->data != stack[sp--])
			return 0;

		slow = slow->next;
	}

	return 1;
}


int
palindrome_recursive(struct Node* head, int length, struct Node** next)
{
	if (head == NULL || length <= 0)
	{
		(*next) = head;
		return 1;
	}
	else if(length == 1)
	{
		(*next) = head->next;
		return 1;
	}

	int result = palindrome_recursive(head->next, length-2, next);

	if (!result || (*next) == NULL)
		return 0;

	if (head->data != (*next)->data)
		return 0;

	(*next) = (*next)->next;

	return 1;
}


struct Node*
intersection(struct Node* a, struct Node* b)
{
	if (a == NULL || b == NULL)
		return NULL;

	// O(A + B) Time Complexity
	// O(1)     Space Complexity
	int counter_a = 0;
	int counter_b = 0;
	struct Node* head_a = a;
	struct Node* head_b = b;

	for(; a->next != NULL; a = a->next)
		counter_a++;

	for(; b->next != NULL; b = b->next)
		counter_b++;

	if (a != b)
		return NULL; // There is no intersection


	// Chop off the difference from the front of the longer List
	if (counter_a > counter_b)
	{
		counter_a = counter_a - counter_b;
		while (counter_a--)
			head_a = head_a->next;
	}
	else
	{
		counter_b = counter_b - counter_a;
		while (counter_b--)
			head_b = head_b->next;
	}

	while(head_a != head_b)
	{
		head_a = head_a->next;
		head_b = head_b->next;
	}

	return head_a;
}


struct Node*
beginning_of_loop(struct Node* head)
{
	struct Node* slow = head;
	struct Node* fast = head;

	/*
		After k steps slow is at the start of the Loop
		and fast is k steps into the loop.

		That means they will meet after LOOP_SIZE - k turns.
		And at that point they will be at exactly k nodes away from
		the start of the Loop.
	*/

	// Detect if Linked List has a Loop
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			break;
	}

	// There is no Loop in the List
	if (fast == NULL || fast->next == NULL)
		return NULL;

	/*
		Move slow to head and keep fast at Meeting point. Each
		are k steps from the Loop start. If they move at the same pace
		they must meet at Loop start.
	*/
	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	// Both now point to the start of the Loop
	return slow;
}


void
swap_every_two(struct Node** head)
{
	// Base case
	if ((*head) == NULL || (*head)->next == NULL)
		return;

	// Initialize
	struct Node* left  = (*head);
	struct Node* right = (*head)->next->next;
	struct Node* left_prev = NULL;

	while (right != NULL)
	{
		struct Node* between  = left->next;
		struct Node* right_next = right->next;

		left->next = right_next;
		between->next = left;

		right->next = between;

		if ((*head) == left)
			(*head) = right;
		else
			left_prev->next = right;

		// Swap left and right pointers
		between = left;
		left = right;
		right = between;

		// Prepare for the next
		left_prev = left;
		left = left->next;
		right = right->next;
	}

	printf("\n\tEvery two nodes have been swapped!\n\n");
}
