#include "Link.h"
#include<stdio.h>
#include<stdlib.h>

Node* init(Node *pnode) {
	pnode = (Node*)malloc(sizeof(Node));
	pnode->next = NULL;
	return pnode;
}

int insertList(Node **phead, LINK_TYPE value) {
	if (*phead == NULL) {
		*phead = init(*phead);
	}
	Node *next = NULL;
	next = init(next);
	if (next == NULL)
		return FALSE;
	next->value = value;
	while ((*phead)->next)
	{
		*phead = (*phead)->next;
	}
	(*phead)->next = next;
	return TRUE;
}

void printList(Node *phead) {
	while (phead != NULL)
	{
		printf("%d\n", phead->value);
		phead = phead->next;
	}
}