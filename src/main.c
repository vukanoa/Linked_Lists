#include "singly_linked_list.h"
#include "doubly_linked_list.h"
#define HIGHEST_OPTION 13
#define LOWEST_OPTION 0
#define NO_INTERSECTION -1

void
main_menu()
{
	struct Node* head = NULL;
	struct Node* tail = NULL;
	struct Node* tmp  = NULL;

	int option = -1;
	int number;
	char sorted = 0;
	while (option != 0)
	{
		printf("==============================================\n");
		printf("============== SELECT AN OPTION ==============\n");
		printf("==============================================\n");

		printf("\t    1. Push in List\n");
		printf("\t    2. Put in List\n");
		printf("\t    3. Insert in a sorted list\n");
		printf("\t    4. Search for Element\n");
		printf("\t    5. Remove from List\n");
		printf("\t    6. Reverse List\n");
		printf("\t    7. Print List\n");
		printf("\t    8. Generate random List\n");
		printf("\t    9. Selection Sort a list\n");
		printf("\t   10. Bubble Sort a list\n");
		printf("\t   11. Merge Sort a list\n");
		printf("\t   12. Quick Sort a list\n");
		printf("\t   13. Destroy a list\n");
		printf("\t    0. Exit\n");

		printf("\n: ");
		scanf("%d", &option);

		if (option < LOWEST_OPTION || option > HIGHEST_OPTION)
		{
			printf("\n\tERROR: That option doesn't exist! Try again.\n\n");
			continue;
		}

		switch (option)
		{
			case 1:
				printf("Which element would you like to PUSH?\nElement: ");
				scanf("%d<CR>", &number);

				push(&head, number, &tail);

				if (head->next != NULL)
				{
					if (head->data > head->next->data)
						sorted = 0;
				}
				break;

			case 2:
				printf("Which element would you like to PUT?\nElement: ");
				scanf("%d<CR>", &number);

				put(&head, number, &tail);
				tmp = head;
				while (tmp->next)
				{
					if (tmp->next == tail)
					{
						if (tmp->data > tail->data)
							sorted = 0;

						break;
					}
					else
						tmp = tmp->next;
				}

				break;

			case 3:
				if (sorted)
				{
					printf("Which element would you like to INSERT in a sorted list?\nElement: ");
					scanf("%d<CR>", &number);

					insert(&head, number);
				}
				else
					printf("\n\tERROR: A list isn't sorted. Try to sort it first.\n\n");

				break;

			case 4:
				printf("Search for Element: ");
				scanf("%d", &number);
				int found = find(head, number);

				if (found)
					printf("\n\tElement %d exists in the List!\n\n", number);
				else
					printf("\n\tElement %d does NOT exit in the List!\n\n", number);

				break;

			case 5:
				printf("Which element would you like to DELETE?\nElement: ");
				scanf("%d<CR>", &number);

				erase(&head, number, &tail);
				break;

			case 6:
				reverse_list(&head);	
				break;

			case 7:
				printf("\tCurrent List:");
				print_list(head);
				break;

			case 8:
				generate_list(&head, &tail);
				break;

			case 9:
				selection_sort(head);
				sorted = 1;
				break;

			case 10:
				bubble_sort(head);
				sorted = 1;
				break;

			case 11:
				merge_sort(&head);
				sorted = 1;
				if (head == NULL || head->next == NULL)
					printf("\n\tThere's nothing to sort!\n\n");
				else
					printf("\n\tA List has been successfully Merge-sorted!\n\n");

				break;

			case 12:
				quick_sort(head, tail);
				sorted = 1;
				if (head == NULL || head->next == NULL)
					printf("\n\tThere's nothing to sort!\n\n");
				else
					printf("\n\tA List has been successfully Quick-sorted!\n\n");

				break;

			case 13: 
				destroy_list(&head);
				break;

			case 0:
				option = 0;
				continue;
		}
	}
}

int
main()
{
	// -----------------------
	// ------- TESTING -------
	// -----------------------

	struct Node* head_a = NULL;
	struct Node* tail_a = NULL; // Comment for TEST 0 to prevent Warning

	struct Node* head_b = NULL;
	struct Node* tail_b = NULL; // Comment for TEST 0 to prevent Warning

	// TEST 0
	// Works for Empty Lists as well

	// TEST 1
	// put(&head_b, 7, &tail_b);

	// TEST 2
	// put(&head_a, 1, &tail_a);
	// put(&head_a, 2, &tail_a);
	// put(&head_a, 3, &tail_a);
	// put(&head_a, 4, &tail_a);
	// put(&head_a, 5, &tail_a);

	// put(&head_b, 7, &tail_b);
	// put(&head_b, 8, &tail_b);
	// put(&head_b, 9, &tail_b);
	// tail_b->next = head_a->next->next;

	// TEST 3
	// put(&head_a, 1, &tail_a);
	// put(&head_a, 2, &tail_a);
	// put(&head_a, 3, &tail_a);
	// put(&head_a, 4, &tail_a);
	// put(&head_a, 5, &tail_a);

	// put(&head_b, 6, &tail_b);
	// put(&head_b, 0, &tail_b);
	// put(&head_b, 1, &tail_b);
	// put(&head_b, 7, &tail_b);
	// put(&head_b, 8, &tail_b);
	// put(&head_b, 9, &tail_b);
	// tail_b->next = head_a->next->next;

	// TEST 4
	// put(&head_a, 1, &tail_a);
	// put(&head_a, 2, &tail_a);
	// put(&head_a, 3, &tail_a);
	// put(&head_a, 4, &tail_a);
	// put(&head_a, 5, &tail_a);

	// put(&head_b, 1, &tail_b);
	// put(&head_b, 2, &tail_b);
	// put(&head_b, 3, &tail_b);
	// put(&head_b, 4, &tail_b);
	// put(&head_b, 5, &tail_b);

	// TEST 5
	// put(&head_a, 1, &tail_a);
	// put(&head_b, 4, &tail_b);
	// put(&head_b, 3, &tail_b);

	// TEST 6
	// put(&head_a, 3, &tail_a);
	// head_b = head_a;
	// tail_b = tail_a;
	// put(&head_b, 4, &tail_b);
	// put(&head_b, 5, &tail_b);

	// TEST 7
	// put(&head_a, 2, &tail_a);
	// put(&head_a, 7, &tail_a);
	// put(&head_a, 5, &tail_a);

	// TEST 8
	// put(&head_a, 1, &tail_a);
	// put(&head_a, 2, &tail_a);
	// put(&head_a, 3, &tail_a);
	// put(&head_a, 4, &tail_a);
	// put(&head_a, 5, &tail_a);

	// put(&head_b, 6, &tail_b);
	// put(&head_b, 1, &tail_b);
	// put(&head_b, 7, &tail_b);
	// put(&head_b, 8, &tail_b);
	// put(&head_b, 9, &tail_b);
	// tail_b->next = tail_a;

	// TEST 9
	put(&head_a, 2, &tail_a);
	put(&head_a, 4, &tail_a);
	put(&head_a, 3, &tail_a);
	put(&head_a, 6, &tail_a);
	put(&head_a, 4, &tail_a);
	put(&head_a, 1, &tail_a);
	put(&head_a, 5, &tail_a);

	put(&head_b, 9, &tail_b);
	put(&head_b, 3, &tail_b);
	put(&head_b, 7, &tail_b);
	put(&head_b, 8, &tail_b);
	put(&head_b, 9, &tail_b);
	tail_a->next = head_b->next->next->next;

	printf("\n\n");
	printf("\t==================================\n");
	printf("\t========== INTERSECTION ==========\n");
	printf("\t==================================\n");
	printf("\n\n");

	printf("List A:");
	print_list(head_a);

	printf("List B:");
	print_list(head_b);

	head_a = intersection(head_a, head_b);
	printf("\n\tIntersection at Node: %d\n\n", head_a ? head_a->data : NO_INTERSECTION);

	if (!head_a)
		printf("\t[%d means => There is no intersection!]\n\n", NO_INTERSECTION);


	return 0;
}
