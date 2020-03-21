#include <stdio.h>
#include <stdlib.h>
#include "clist.h"

Node *reverseList(Node *head)
{
	if (NULL == head || NULL == head->next)
		return head;

	Node *pre = head;
	Node *cur = head->next;
	Node *tmp;
	while(cur){
		tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}

	head->next = NULL;
	return pre;
}

Node *recursiveReverse(Node *head)
{
	if(NULL==head || NULL==head->next)
		return head;

	Node *newHead = recursiveReverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return newHead;
}

Node *appendNode(Node *head, int val)
{
	Node *p = (Node *)malloc(sizeof(Node));
	p->val = val;
	p->next = NULL;
	if(head == NULL)
	{
		head = p;
		return head;
	}
	p->next = head;
	head = p;
	return head;
}


void printList(Node *head)
{
	Node *p = head;
	printf("List(%p) info\n", head);
	while(p != NULL)
	{
		printf("%d->", p->val);
		p = p->next;
	}
	printf("NULL\n");
}

void destroy(List **list)
{
	List *li = *list;
	if(li == NULL)
		return;

	Node *cur = li->head;
	while(cur)
	{
		Node *tmp = cur->next;
		free(cur);
		cur = tmp;
	}

	free(li);
	*list = NULL;
}
