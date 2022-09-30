#include "list.h"

int
main ()
{
	int data;

	for (int i = 0; i < 3; i++)
	{
		printf("Which element would you like to insert?\n: ");
		scanf("%d", &data);

		push(data);
	}

	print_list();

	printf("Program executed successfully!\n");

	return 0;
}
