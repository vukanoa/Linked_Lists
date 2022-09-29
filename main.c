#include "list.h"

int
main ()
{
	int data;

	printf("Which element would you like to insert?\n: ");
	scanf("%d", &data);

	put(data);

	printf("Program executed successfully!\n");

	return 0;
}
