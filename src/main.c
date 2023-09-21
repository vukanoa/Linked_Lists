#include <stdlib.h>

#include "singly_linked_list.h"
#include "doubly_linked_list.h"
#define HIGHEST_OPTION 14
#define LOWEST_OPTION 0
#define NO_LOOP -1

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
		printf("\t   14. Swap every two nodes in a list\n");
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

			case 14:
				swap_every_two(&head);
				break;

			case 0:
				option = 0;
				continue;
		}
	}
}

void test_add_two_numbers()
{
	/***** Example 1 *****/
	/*
		l1  = 2 -> 4 -> 3
		l2  = 5 -> 6 -> 4

		res = 7 -> 0 -> 8
	*/
	/* First List */
	struct Node* two_1   = (struct Node*)malloc(sizeof(struct Node)); two_1->data   = 2;
	struct Node* four_1  = (struct Node*)malloc(sizeof(struct Node)); four_1->data  = 4;
	struct Node* three_1 = (struct Node*)malloc(sizeof(struct Node)); three_1->data = 3;
	two_1->next  = four_1;
	four_1->next = three_1;

	/* Second List */
	struct Node* five_2  = (struct Node*)malloc(sizeof(struct Node)); five_2->data = 5;
	struct Node* six_2   = (struct Node*)malloc(sizeof(struct Node)); six_2->data  = 6;
	struct Node* four_2  = (struct Node*)malloc(sizeof(struct Node)); four_2->data = 4;
	five_2->next = six_2;
	six_2->next  = four_2;

	/* A & B */
	struct Node* l1 = two_1;
	struct Node* l2 = five_2;



	/***** Example 2 *****/
	/*
		l1  = 2 -> 4 -> 3
		l2  = 5 -> 6

		res = 7 -> 0 -> 4
	*/
	// /* First List */
	// struct Node* two_1   = (struct Node*)malloc(sizeof(struct Node)); two_1->data   = 2;
	// struct Node* four_1  = (struct Node*)malloc(sizeof(struct Node)); four_1->data  = 4;
	// struct Node* three_1 = (struct Node*)malloc(sizeof(struct Node)); three_1->data = 3;
	// two_1->next  = four_1;
	// four_1->next = three_1;

	// /* Second List */
	// struct Node* five_2  = (struct Node*)malloc(sizeof(struct Node)); five_2->data = 5;
	// struct Node* six_2   = (struct Node*)malloc(sizeof(struct Node)); six_2->data  = 6;
	// five_2->next = six_2;

	// /* A & B */
	// struct Node* l1 = two_1;
	// struct Node* l2 = five_2;



	/***** Example 3 *****/
	/*
		l1  = 4 -> 3
		l2  = 5 -> 6 -> 4

		res = 9 -> 9 -> 4
	*/
	// /* First List */
	// struct Node* four_1  = (struct Node*)malloc(sizeof(struct Node)); four_1->data  = 4;
	// struct Node* three_1 = (struct Node*)malloc(sizeof(struct Node)); three_1->data = 3;
	// four_1->next = three_1;

	// /* Second List */
	// struct Node* five_2  = (struct Node*)malloc(sizeof(struct Node)); five_2->data = 5;
	// struct Node* six_2   = (struct Node*)malloc(sizeof(struct Node)); six_2->data  = 6;
	// struct Node* four_2  = (struct Node*)malloc(sizeof(struct Node)); four_2->data = 4;
	// five_2->next = six_2;
	// six_2->next  = four_2;

	// /* A & B */
	// struct Node* l1 = four_1;
	// struct Node* l2 = five_2;



	/***** Example 4 *****/
	/*
		l1  = 7
		l2  = NULL/	

		res = 7
	*/
	// /* First List */
	// struct Node* seven_1 = (struct Node*)malloc(sizeof(struct Node)); seven_1->data = 7;

	// /* Second List */
	// /* Empty */

	// /* A & B */
	// struct Node* l1 = seven_1;
	// struct Node* l2 = NULL;



	/***** Example 5 *****/
	/*
		l1  = NULL
		l2  = 5	

		res = 5
	*/
	// /* First List */
	// /* Empty */

	// /* Second List */
	// struct Node* five_2 = (struct Node*)malloc(sizeof(struct Node)); five_2->data = 5;

	// /* A & B */
	// struct Node* l1 = NULL;
	// struct Node* l2 = five_2;



	/***** Example 6 *****/
	/*
		l1  = NULL
		l2  = NULL	

		res = NULL
	*/
	// /* First List */
	// /* Empty */

	// /* Second List */
	// /* Empty */

	// /* A & B */
	// struct Node* l1 = NULL;
	// struct Node* l2 = NULL;



	printf("\n\t=======================");
	printf("\n\t=== ADD TWO NUMBERS ===");
	printf("\n\t=======================\n");

	/* Write Input */
	print_list(l1);
	print_list(l2);

	/* Solution */
	struct Node* result = add_two_numbers(l1, l2);

	/* Write Output */
	print_list(result);
}

int
main()
{
	// -----------------------
	// ------- TESTING -------
	// -----------------------

	// main_menu();
	test_add_two_numbers();

	return 0;
}
