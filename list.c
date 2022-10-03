#include <stdlib.h>
#include <time.h>
#include "list.h"

Node* head = NULL;
Node* tail = NULL;


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
insert(int data)
{
	Node* new_element = (Node*) malloc(sizeof(Node));
	new_element->data = data;
	new_element->next = NULL;

	if (head == NULL || data < head->data)
	{
		new_element->next = head;
		head = new_element;
	}
	else
	{
		Node* cur = head;
		while (cur->next != NULL && cur->next->data < data)
			cur = cur->next;

		new_element->next = cur->next;
		cur->next = new_element;
	}
	printf("\n\tElement %d has been properly inserted to List!\n\n", data);
}


int
erase(int data)
{
	printf("\n\t");

	if (!head)
	{
		printf("List is empty!");
		printf("\n\n");

		return -1;
	}

	Node* prev = NULL;
	Node* cur = head;
	while (cur)
	{
		if (cur->data == data)
		{
			if (cur == head)
				head = cur->next;
			else
				prev->next = cur->next;

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
find(int data)
{
    Node* cur = head;

    while (cur)
    {
        if (cur->data == data)
            return 1;

        cur = cur->next;
    }

    return 0;
}


void
print_list()
{
    Node* cur = head;
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
reverse_list()
{
	printf("\n\tList has been reversed successfully!\n\n");

	printf("\tPrevious order:");
	print_list();

	Node* p, *q, *r;
	p = NULL;
	q = head;
	r = head->next;

	while (r != NULL)
	{
		q->next = p;
		p = q;
		q = r;
		r = q->next;
		q->next = p;
	}
	head = q;

	printf("\tCurrent order:");
	print_list();
}


void
generate_list()
{
	int size;
	char destroy;
	Node* tmp = NULL;

	if (head != NULL)
	{
		printf("\n\t Would you like to destroy a previous list? (1-yes, 0-no).\n");
		printf("   !!!   WARNING: If you don't there will be memory leak!\n: ");
		scanf("%d", &size); // Didn't want to allocate another variable

		if (size == 1)
		{
			while (head)
			{
				tmp = head;
				head = head->next;
				free(tmp);
			}
		printf("\n\tPrevious List has been destroyed!\n\n");

		}
	}
	srand(time(NULL));

	printf("How many elements would you like to have?\n: ");
	scanf("%d", &size);

	for (int i = 0; i < size; i++)
	{
		tmp = (Node*) malloc(sizeof(Node));
		tmp->data = rand() % 100;
		tmp->next = NULL;

		if (head == NULL)
			head = tail = tmp;
		else
		{
			tmp->next = head;
			head = tmp;
		}
	}

	printf("\n\tA list has been successfully generated!\n\n");
}

void
selection_sort()
{
	// Selection sort O(n^2)
	Node *i, *j;
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
bubble_sort()
{
	// Bubble sort O(n^2)
	int swapped;
	Node* cur;
	Node* last_sorted = NULL;

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

void swap(Node *a, Node *b)
{
	int tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}
