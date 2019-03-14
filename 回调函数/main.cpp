#include"Link.h"
#include<stdio.h>

int main() {
	Node *pList = NULL;

	insertList(&pList, 1);
	insertList(&pList, 2);
	printList(pList);

	getchar();
	return 0;
}