#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "cstack.h"

bool isFull(Stack *s)
{
	return s->top >= s->maxSize-1;
}

bool isEmpty(Stack *s)
{
	return s==NULL || s->top < 0;
}

unsigned int size(Stack *s)
{
	if(isEmpty(s))
		return 0;

	return s->top + 1;
}

void init(Stack **s, int n)
{
	Stack *tmp = (Stack *)malloc(sizeof(Stack));
	tmp->button = (int*)malloc(sizeof(int)*n);
	tmp->maxSize = n;
	tmp->top = -1;
	*s = tmp;
}

void destroy(Stack **s)
{
	Stack *st = *s;
	if(st==NULL)
		return;
	
	if(st->button)
	{

		free(st->button);
		st->button = NULL;
	}

	free(st);
	*s = NULL;
}

void extend(Stack *s, int extSz)
{
	if(!isFull(s))
		return;
	
	int sz = 2*s->maxSize;
	if(extSz != 0)
		sz = s->maxSize+extSz;

	int *tmp = (int*)malloc(sizeof(int)*sz);
	memcpy(tmp, s->button, sizeof(int)*s->maxSize);
	free(s->button);
	s->maxSize = sz;
	s->button = tmp;
}


void push(Stack **s, int val)
{
	if(*s==NULL)
	{
		init(s, 10);
	}

	Stack *st = *s;
		
	if(isFull(st))
		extend(st);


	st->button[++(st->top)] = val;

}

void pop(Stack *s)
{
	if (isEmpty(s))
		return;

	s->top--;
}

int get(Stack *s)
{
	if (isEmpty(s))
	{
		printf("error: Stack is empty!\n");
		exit(-1);
	}
	
	return s->button[s->top];
}

void printStack(Stack *s)
{
	if(s==NULL)
	{
		printf("stack(%p) is empty!", s);
		return;
	}

	int i, sz;
	sz = size(s);
	printf("Stack(%p) info\tsize:%d\tcapacity:%d\tbutton:%p\n", s, sz, s->maxSize, s->button);
	for(i=sz-1;i>=0;--i)
		printf("%d\n",s->button[i]);

}

void reverse(Stack *s)
{
	if(isEmpty(s)||size(s) == 1)
		return;
	
	int top = get(s);
	pop(s);
	reverse(s);

	int button = get(s);
	pop(s);
	reverse(s);
	push(&s, top);

	reverse(s);
	push(&s, button);
}


