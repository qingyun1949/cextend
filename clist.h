#ifndef __CLIST_H__
#define __CLIST_H__
#ifdef __cplusplus
extern "C" {
#endif


struct ListNode{
	int val;
	struct ListNode *next;
};

typedef struct ListNode Node;

typedef struct List{
	Node *head;
	Node *tail;
	int length;
}List;

Node *reverseList(Node *head);
Node *recursiveReverse(Node *head);
Node *appendNode(Node *head, int val);
void printList(Node *head);
void destroyList(List **list);



#ifdef __cplusplus
}
#endif
#endif
