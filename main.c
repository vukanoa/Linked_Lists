#include "list.h"
#define HIGHEST_OPTION 11
#define LOWEST_OPTION 0

int
main()
{
	Node* head = NULL;
	Node* tail = NULL;
	Node* tmp  = NULL;

	int option = -1;
	int number;
	char sorted = 0;
	while (option !=0 )
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
		printf("\t   11. Destroy a list\n");
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

				//if (head->data > head->next->data)
					//sorted = 0;
				break;

			case 2:
				printf("Which element would you like to PUT?\nElement: ");
				scanf("%d<CR>", &number);

				put(&head, number, &tail);
				tmp = head;
				for(;;)
				{
					if (tmp->next == tail)
					{
						if (tmp->data > tail->data)
						{
							sorted = 0;
							break;
						}
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

				erase(&head, number);
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
				destroy_list(&head);
				break;

			case 0:
				option = 0;
				continue;
		}

	}

	Node *head_a = NULL;
	Node *tail_a = NULL;

	Node *head_b = NULL;
	Node *tail_b = NULL;


	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~~~~ FIRST EXAMPLE ~~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	// First example
	put(&head_a, 5,  &tail_a);
	put(&head_a, 10, &tail_a);
	put(&head_a, 15, &tail_a);
	put(&head_a, 40, &tail_a);

	put(&head_b, 2,  &tail_b);
	put(&head_b, 3,  &tail_b);
	put(&head_b, 20, &tail_b);

	printf("List A:");
	print_list(head_a);

	printf("List B:");
	print_list(head_b);

	head = sorted_merge(head_a, head_b);
	printf("Final List:");
	print_list(head);

	destroy_list(&head);
	head_a = NULL;
	tail_a = NULL;
	head_b = NULL;
	tail_b = NULL;

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~~~ SECOND EXAMPLE ~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	// Second example
	put(&head_a, 1, &tail_a);
	put(&head_a, 1, &tail_a);

	put(&head_b, 2,  &tail_b);
	put(&head_b, 4,  &tail_b);

	printf("List A:");
	print_list(head_a);

	printf("List B:");
	print_list(head_b);

	head = sorted_merge(head_a, head_b);
	printf("Final List:");
	print_list(head);

    return 0;
}
