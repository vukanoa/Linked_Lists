#include "singly_linked_list.h"
#include "doubly_linked_list.h"
#define HIGHEST_OPTION 13
#define LOWEST_OPTION 0

int
main()
{
	//struct Node* head = NULL;
	//struct Node* tail = NULL;
	//struct Node* tmp  = NULL;

	//int option = -1;
	//int number;
	//char sorted = 0;
	//while (option != 0)
	//{
	//	printf("==============================================\n");
	//	printf("============== SELECT AN OPTION ==============\n");
	//	printf("==============================================\n");

	//	printf("\t    1. Push in List\n");
	//	printf("\t    2. Put in List\n");
	//	printf("\t    3. Insert in a sorted list\n");
	//	printf("\t    4. Search for Element\n");
	//	printf("\t    5. Remove from List\n");
	//	printf("\t    6. Reverse List\n");
	//	printf("\t    7. Print List\n");
	//	printf("\t    8. Generate random List\n");
	//	printf("\t    9. Selection Sort a list\n");
	//	printf("\t   10. Bubble Sort a list\n");
	//	printf("\t   11. Merge Sort a list\n");
	//	printf("\t   12. Quick Sort a list\n");
	//	printf("\t   13. Destroy a list\n");
	//	printf("\t    0. Exit\n");

	//	printf("\n: ");
	//	scanf("%d", &option);

	//	if (option < LOWEST_OPTION || option > HIGHEST_OPTION)
	//	{
	//		printf("\n\tERROR: That option doesn't exist! Try again.\n\n");
	//		continue;
	//	}

	//	switch (option)
	//	{
	//		case 1:
	//			printf("Which element would you like to PUSH?\nElement: ");
	//			scanf("%d<CR>", &number);

	//			push(&head, number, &tail);

	//			if (head->next != NULL)
	//			{
	//				if (head->data > head->next->data)
	//					sorted = 0;
	//			}
	//			break;

	//		case 2:
	//			printf("Which element would you like to PUT?\nElement: ");
	//			scanf("%d<CR>", &number);

	//			put(&head, number, &tail);
	//			tmp = head;
	//			while (tmp->next)
	//			{
	//				if (tmp->next == tail)
	//				{
	//					if (tmp->data > tail->data)
	//						sorted = 0;

	//					break;
	//				}
	//				else
	//					tmp = tmp->next;
	//			}

	//			break;

	//		case 3:
	//			if (sorted)
	//			{
	//				printf("Which element would you like to INSERT in a sorted list?\nElement: ");
	//				scanf("%d<CR>", &number);

	//				insert(&head, number);
	//			}
	//			else
	//				printf("\n\tERROR: A list isn't sorted. Try to sort it first.\n\n");

	//			break;

	//		case 4:
	//			printf("Search for Element: ");
	//			scanf("%d", &number);
	//			int found = find(head, number);

	//			if (found)
	//				printf("\n\tElement %d exists in the List!\n\n", number);
	//			else
	//				printf("\n\tElement %d does NOT exit in the List!\n\n", number);

	//			break;

	//		case 5:
	//			printf("Which element would you like to DELETE?\nElement: ");
	//			scanf("%d<CR>", &number);

	//			erase(&head, number, &tail);
	//			break;

	//		case 6:
	//			reverse_list(&head);	
	//			break;

	//		case 7:
	//			printf("\tCurrent List:");
	//			print_list(head);
	//			break;

	//		case 8:
	//			generate_list(&head, &tail);
	//			break;

	//		case 9:
	//			selection_sort(head);
	//			sorted = 1;
	//			break;

	//		case 10:
	//			bubble_sort(head);
	//			sorted = 1;
	//			break;

	//		case 11:
	//			merge_sort(&head);
	//			sorted = 1;
	//			if (head == NULL || head->next == NULL)
	//				printf("\n\tThere's nothing to sort!\n\n");
	//			else
	//				printf("\n\tA List has been successfully Merge-sorted!\n\n");

	//			break;

	//		case 12:
	//			quick_sort(head, tail);
	//			sorted = 1;
	//			if (head == NULL || head->next == NULL)
	//				printf("\n\tThere's nothing to sort!\n\n");
	//			else
	//				printf("\n\tA List has been successfully Quick-sorted!\n\n");

	//			break;

	//		case 13: 
	//			destroy_list(&head);
	//			break;

	//		case 0:
	//			option = 0;
	//			continue;
	//	}
	//}
	
	struct d_Node* d_head = NULL;
	struct d_Node* d_tail = NULL;

	d_put(&d_head, 1, &d_tail);
	d_put(&d_head, 2, &d_tail); // Comment this and two lines down for TEST 8
	d_put(&d_head, 3, &d_tail);
	d_put(&d_head, 4, &d_tail);
	d_put(&d_head, 5, &d_tail);

	// -----------------------
	// ------- TESTING -------
	// -----------------------

	// Print Before
	printf("\n\n------- BEFORE -------\n");
	d_print_list(d_head);

	// TEST 1 -> Swap (2 & 3)
	// struct d_Node* two   = d_head->next;
	// struct d_Node* three = two->next;
	// printf("Head:\t%d\n",  d_head->data);
	// printf("Two:\t%d\n",   two->data);
	// printf("Three:\t%d\n", three->data);
	// printf("Tail:\t%d\n",  d_tail->data);

	// TEST 2 -> Swap (2 & 4)
	// struct d_Node* two  = d_head->next;
	// struct d_Node* four = d_tail->prev;
	// printf("Head:\t%d\n", d_head->data);
	// printf("Two:\t%d\n",  two->data);
	// printf("Four:\t%d\n", four->data);
	// printf("Tail:\t%d\n", d_tail->data);

	// TEST 3 -> Swap (1 & 4)
	// struct d_Node* one  = d_head;
	// struct d_Node* four = d_tail->prev;
	// printf("Head:\t%d\n", d_head->data);
	// printf("One:\t%d\n",  one->data);
	// printf("Four:\t%d\n", four->data);
	// printf("Tail:\t%d\n", d_tail->data);

	// TEST 4 -> Swap (2 & 5)
	// struct d_Node* two  = d_head->next;
	// struct d_Node* five = d_tail;
	// printf("Head:\t%d\n", d_head->data);
	// printf("Two:\t%d\n",  two->data);
	// printf("Five:\t%d\n", five->data);
	// printf("Tail:\t%d\n", d_tail->data);

	// TEST 5 -> Swap (1 & 5)
	// struct d_Node* one  = d_head;
	// struct d_Node* five = d_tail;
	// printf("Head:\t%d\n", d_head->data);
	// printf("One:\t%d\n",  one->data);
	// printf("Five:\t%d\n", five->data);
	// printf("Tail:\t%d\n", d_tail->data);

	// TEST 6 -> Swap (4 & 5)
	// struct d_Node* four  = d_tail->prev;
	// struct d_Node* five  = d_tail;
	// printf("Head:\t%d\n",  d_head->data);
	// printf("Four:\t%d\n",  four->data);
	// printf("Five:\t%d\n",  five->data);
	// printf("Tail:\t%d\n",  d_tail->data);

	// TEST 7 -> Swap (1 & 2)
	// struct d_Node* one =  d_head;
	// struct d_Node* two =  d_head->next;
	// printf("Head:\t%d\n", d_head->data);
	// printf("One:\t%d\n",  one->data);
	// printf("Two:\t%d\n",  two->data);
	// printf("Tail:\t%d\n", d_tail->data);

	// TEST 8 -> Swap (1 & 5) When 1 & 5 are the only nodes
	// struct d_Node* one =   d_head;
	// struct d_Node* five =  d_head->next;
	// printf("Head:\t%d\n",  d_head->data);
	// printf("One:\t%d\n",   one->data);
	// printf("Five:\t%d\n",  five->data);
	// printf("Tail:\t%d\n",  d_tail->data);



	// List: 1 2 3 4 5
	// Test 1 -> Swap (2 & 3)
	// swap_pointers(&d_head, &two, &three, &d_tail);

	// TEST 2 -> Swap (2 & 4)
	// swap_pointers(&d_head, &two, &four, &d_tail);

	// TEST 3 -> Swap (1 & 4)
	// swap_pointers(&d_head, &one, &four, &d_tail);

	// TEST 4 -> Swap (2 & 5)
	// swap_pointers(&d_head, &two, &five, &d_tail);

	// TEST 5 -> Swap (1 & 5)
	// swap_pointers(&d_head, &one, &five, &d_tail);

	// TEST 6 -> Swap (4 & 5)
	// swap_pointers(&d_head, &four, &five, &d_tail);

	// TEST 7 -> Swap (1 & 2)
	// swap_pointers(&d_head, &one, &two, &d_tail);

	// TEST 8 -> Swap (1 & 5) When 1 & 5 are the only nodes
	// swap_pointers(&d_head, &one, &five, &d_tail);


	// Print After
	printf("\n\n\n\n------- AFTER -------\n");
	d_print_list(d_head);

	// TEST 1 -> Swap (2 & 3)
	// printf("Head:\t%d\n",  d_head->data);
	// printf("Two:\t%d\n",   two->data);
	// printf("Three:\t%d\n", three->data);
	// printf("Tail:\t%d\n",  d_tail->data);

	// TEST 2 -> Swap (2 & 4)
	// printf("Head:\t%d\n", d_head->data);
	// printf("Two:\t%d\n",  two->data);
	// printf("Four:\t%d\n", four->data);
	// printf("Tail:\t%d\n", d_tail->data);

	// TEST 3 -> Swap (1 & 4)
	// printf("Head:\t%d\n", d_head->data);
	// printf("One:\t%d\n",  one->data);
	// printf("Four:\t%d\n", four->data);
	// printf("Tail:\t%d\n", d_tail->data);

	// TEST 4 -> Swap (2 & 5)
	// printf("Head:\t%d\n", d_head->data);
	// printf("Two:\t%d\n",  two->data);
	// printf("Five:\t%d\n", five->data);
	// printf("Tail:\t%d\n", d_tail->data);

	// TEST 5 -> Swap (1 & 5)
	// printf("Head:\t%d\n", d_head->data);
	// printf("One:\t%d\n",  one->data);
	// printf("Five:\t%d\n", five->data);
	// printf("Tail:\t%d\n", d_tail->data);

	// TEST 6 -> Swap (4 & 5)
	// printf("Head:\t%d\n",  d_head->data);
	// printf("Four:\t%d\n",  four->data);
	// printf("Five:\t%d\n",  five->data);
	// printf("Tail:\t%d\n",  d_tail->data);

	// TEST 7 -> Swap (1 & 2)
	// printf("Head:\t%d\n", d_head->data);
	// printf("One:\t%d\n",  one->data);
	// printf("Two:\t%d\n",  two->data);
	// printf("Tail:\t%d\n", d_tail->data);

	// TEST 8 -> Swap (1 & 5) When 1 & 5 are the only nodes
	// printf("Head:\t%d\n",  d_head->data);
	// printf("One:\t%d\n",   one->data);
	// printf("Five:\t%d\n",  five->data);
	// printf("Tail:\t%d\n",  d_tail->data);

    return 0;
}
