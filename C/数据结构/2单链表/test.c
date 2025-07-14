#define _CRT_SECURE_NO_WARNINGS

#include "SList.h"

int main()
{
	/*SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node5 = (SLTNode*)malloc(sizeof(SLTNode));

	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;
	node5->data = 5;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;

	print(node1);
	SLTPushBack(node1, 6);
	print(node1);*/


	// 创建一个空链表
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	print(plist);
	SLTPushBack(&plist, 2);
	print(plist);
	SLTPushBack(&plist, 3);
	print(plist);
	SLTPushBack(&plist, 4);
	print(plist);
	SLTPushFront(&plist, 5);
	print(plist);

	//SLTPopBack(&plist);
	//print(plist);
	/*SLTPopBack(plist);
	print(plist);
	SLTPopBack(plist);
	print(plist);
	SLTPopBack(plist);
	print(plist);
	SLTPopBack(plist);
	SLTPopBack(plist);
	print(plist);*/

	SLTPopFront(&plist);
	print(plist);

	//printf("%p\n", Find(plist, 4));

	InsertFront(&plist, Find(plist, 4), 9);
	print(plist);

	
	InsertBack(Find(plist, 4), 7);
	print(plist);

	EraseAfter(Find(plist, 4));
	print(plist);

	return 0;
}