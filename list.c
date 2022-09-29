#include <stdlib.h>
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

