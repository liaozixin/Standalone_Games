#pragma once
#define LINK_TYPE int
#define FALSE 0
#define TRUE 1

typedef struct LINK_NODE {
	LINK_TYPE value;
	struct LINK_NODE *next;
} Node;


int insertList(Node **phead, LINK_TYPE);
void printList(Node *phead);