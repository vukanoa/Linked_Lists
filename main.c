#include "list.h"

int
main()
{
	int option = -1;
	int number;
	char sorted = 0;
	while (option !=0 )
	{
		printf("==============================================\n");
		printf("============== SELECT AN OPTION ==============\n");
		printf("==============================================\n");

		printf("1. Put in List\n");
		printf("2. Push in List\n");
		printf("3. Insert in a sorted list\n");
		printf("4. Search for Element\n");
		printf("5. Remove from List\n");
		printf("6. Reverse List\n");
		printf("7. Print List\n");
		printf("8. Generate random List\n");
		printf("9. Sort a list\n");
		printf("0. Exit\n");

		printf("\n: ");
		scanf("%d", &option);

		if (option < 0)
		{
			printf("\nNEMA TE OPCIJE!\n\n");
			continue;
		}

		switch (option)
		{
			case 1:
				printf("Which element would you like to PUT?\nElement: ");
				scanf("%d<CR>", &number);

				put(number);
				break;

			case 2:
				printf("Which element would you like to PUSH?\nElement: ");
				scanf("%d<CR>", &number);

				push(number);
				break;

			case 3:
				if (sorted)
				{
					printf("Which element would you like to INSERT in a sorted list?\nElement: ");
					scanf("%d<CR>", &number);

					insert(number);
				}
				else
					printf("\n\tError: A list isn't sorted. Try to sort it first.\n\n");

				break;

			case 4:
				printf("Search for Element: ");
				scanf("%d", &number);
				int found = find(number);

				if (found)
					printf("\n\tElement %d exists in the List!\n\n", number);
				else
					printf("\n\tElement %d does NOT exit in the List!\n\n", number);

				break;

			case 5:
				printf("Which element would you like to DELETE?\nElement: ");
				scanf("%d<CR>", &number);

				erase(number);
				break;

			case 6:
				reverse_list();	
				break;

			case 7:
				printf("\tCurrent List:");
				print_list();
				break;

			case 8:
				generate_list();
				break;

			case 9:
				sort_list();
				sorted = 1;
				break;

			case 0:
				option = 0;
				continue;
		}

	}

    return 0;

}
