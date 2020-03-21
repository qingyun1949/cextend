#ifndef __CSTACK_H__
#define __CSTACK_H__
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

struct _Stack{
	int *button;
	int top;
	int maxSize;
};
typedef struct _Stack Stack;

bool isFull(Stack *s);
bool isEmpty(Stack *s);
unsigned int size(Stack *s);
void init(Stack **s, int n);
void destroy(Stack **s);
void extend(Stack *s, int extSz);
void push(Stack **s, int val);
void pop(Stack *s);
int get(Stack *s);
void printStack(Stack *s);
void reverse(Stack *s);
#ifdef __cplusplus
}
#endif
#endif
