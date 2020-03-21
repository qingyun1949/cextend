#include <stdio.h>
#include <stdlib.h>

#include "cstack.h"
#include "clist.h"

void test_stack()
{
	Stack *s=NULL; 
	int i;
	for(i=0;i<5;i++)
		push(&s, i);

	printStack(s);
	printf("test for extend:\n");
	for(;i<15;i++)
		push(&s, i);
	printStack(s);
	
	printf("test for reverse:\n");
	reverse(s);
	printStack(s);

	printf("test for destroy:\n");
	destroy(&s);
	printStack(s);

}

void test_list()
{
	Node *head = NULL;
	int i = 0;
	for(;i<10; i++)
		head = appendNode(head, i);
	printList(head);

	head = reverseList(head);
	printf("after reverse\n");
	printList(head);
	printf("reverse by recursive again\n");
	head = recursiveReverse(head);
	printList(head);

}

int main()
{
	test_stack();
	test_list();
	return 0;
}
