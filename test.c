#include "cstack.h"
#include <stdio.h>
#include <stdlib.h>

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

int main()
{
	test_stack();
	return 0;
}
