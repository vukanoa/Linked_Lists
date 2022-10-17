#include "singly_linked_list.h"
#include "doubly_linked_list.h"
#define HIGHEST_OPTION 13
#define LOWEST_OPTION 0

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

	struct Node* head = NULL;
	struct Node* tail = NULL; // Comment for TEST 0 to prevent Warning

	// TEST 0
	// Empty List

	// TEST 1
	//put(&head, 2, &tail);
	//put(&head, 2, &tail);
	//put(&head, 2, &tail);
	//put(&head, 2, &tail);
	//put(&head, 2, &tail);
	//put(&head, 5, &tail);
	//put(&head, 2, &tail);
	//put(&head, 3, &tail);
	//put(&head, 4, &tail);
	//put(&head, 7, &tail);
	//put(&head, 4, &tail);
	//put(&head, 4, &tail);
	//put(&head, 8, &tail);
	
	// TEST 2
	// put(&head, 2, &tail);
	// put(&head, 5, &tail);
	// put(&head, 2, &tail);
	// put(&head, 3, &tail);
	// put(&head, 4, &tail);
	// put(&head, 7, &tail);
	// put(&head, 4, &tail);
	// put(&head, 4, &tail);
	// put(&head, 8, &tail);
	// put(&head, 8, &tail);
	// put(&head, 8, &tail);
	// put(&head, 8, &tail);

	// TEST 3
	// put(&head, 3, &tail);
	// put(&head, 6, &tail);
	// put(&head, 2, &tail);
	// put(&head, 3, &tail);
	// put(&head, 4, &tail);
	// put(&head, 7, &tail);
	// put(&head, 3, &tail);
	// put(&head, 4, &tail);
	// put(&head, 8, &tail);
	// put(&head, 11, &tail);
	// put(&head, 11, &tail);
	// put(&head, 8, &tail);
	// put(&head, 7, &tail);
	// put(&head, 13, &tail);
	
	// TEST 4
	put(&head, 1, &tail);
	put(&head, 3, &tail);
	put(&head, 6, &tail);
	put(&head, 2, &tail);
	put(&head, 3, &tail);
	put(&head, 4, &tail);
	put(&head, 7, &tail);
	put(&head, 3, &tail);
	put(&head, 4, &tail);
	put(&head, 8, &tail);
	put(&head, 11, &tail);
	put(&head, 11, &tail);
	put(&head, 8, &tail);
	put(&head, 3, &tail);
	put(&head, 3, &tail);
	put(&head, 7, &tail);
	put(&head, 13, &tail);

	printf("\n\n");
	printf("\t=========================\n");
	printf("\t=== REMOVE DUPLICATES ===\n");
	printf("\t=========================\n");
	printf("\n\n");

	printf("Before:");
	print_list(head);

	remove_duplicates(head);

	printf("After:");
	print_list(head);

    return 0;
}
