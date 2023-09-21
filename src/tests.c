#include "tests.h"

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

