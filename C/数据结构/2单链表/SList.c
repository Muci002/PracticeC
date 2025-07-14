#define _CRT_SECURE_NO_WARNINGS

#include "SList.h"

void print(SLTNode * slt)
{
	assert(slt);
	for (SLTNode* p = slt; p != NULL; p = p->next)
	{
		printf("%d -> ", p->data);
	}
	printf("NULL\n");
	return 0;
}

// 为新元素分配空间 
SLTNode* SLTBuyNode(SLDatatype x)
{
	/*SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;*/

	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	if (node == NULL)
	{
		perror("malloc");
		exit(1);
	}
	node->data = x;
	node->next = NULL;

	return node;
}

// 尾插
void SLTPushBack(SLTNode** pphead, SLDatatype x)  // 二级指针可以修改指针本身的值
{
	assert(pphead);

	// 为新元素分配空间
	SLTNode* node = SLTBuyNode(x);

	/*SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	node->data = x;
	node->next = NULL;*/

	// 判断是否为空链表
	if (*pphead == NULL) *pphead = node;
	else
	{
		SLTNode* p = *pphead;
		for (; p->next != NULL; p = p->next);
		p->next = node;
	}
}

// 头插
void SLTPushFront(SLTNode** pphead, SLDatatype x)
{
	assert(pphead);
	// 为新来的元素分配空间
	SLTNode* node = SLTBuyNode(x);
	node->next = *pphead;
	*pphead = node;
}

// 尾删
void SLTPopBack(SLTNode** pphead)
{
	//assert(pphead);
	//// 链表为空
	//if (*pphead == NULL) return;

	//// 链表只有一个元素
	//if ((*pphead)->next == NULL)
	//{
	//	free(*pphead);
	//	*pphead = NULL;
	//	return;
	//}

	//SLTNode* p = *pphead;
	////for (; p->next->next != NULL; p = p->next);
	///*free(p->next);
	//p->next = NULL;*/

	//SLTNode* pre = NULL;
	//while (p->next != NULL)
	//{
	//	pre = p;
	//	p = p->next;
	//}
	//free(p);
	//pre->next = NULL;
	
	//链表为空不能删除
	assert(pphead && *pphead);
	//链表只有一个节点的情况
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else {
		SLTNode* prev = NULL;
		SLTNode* ptail = *pphead;
		while (ptail->next)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		//prev ptail
		prev->next = NULL;
		free(ptail);
		ptail = NULL;
	}

}

// 头删
void SLTPopFront(SLTNode** pphead)
{
	//assert(pphead && *pphead);

	//// 当链表只有一个节点的时候
	//if ((*pphead)->next == NULL)
	//{
	//	free(*pphead);
	//	*pphead = NULL;
	//	return;
	//}

	//// 释放头节点
	//*pphead = (*pphead)->next;


	assert(pphead && *pphead);
	SLTNode* node = (*pphead)->next;
	free(*pphead);
	*pphead = node;

}


// 查找
SLTNode* Find(SLTNode* phead, SLDatatype x)
{
	for (SLTNode* p = phead; p != NULL; p = p->next)
	{
		if (p->data == x) return p;
	}

	return NULL;
}

// 在指定位置之前插入数据
void InsertFront(SLTNode** pphead, SLTNode* pos, SLDatatype x)
{
	assert(pphead && pos);

	SLTNode* cur = *pphead;

	if (cur == pos) SLTPushFront( pphead,x);

	while (cur->next != pos) cur = cur->next;
	// 申请一个新节点
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = cur->next;
	cur->next = newnode;

}

// 在指定位置之后插入数据
void InsertBack(SLTNode* pos, SLDatatype x)
{
	assert(pos);
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

// 删除pos节点
void Erase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && pos);
	if (*pphead == pos) SLTPopFront(pphead);

	// 找到pos之前的节点
	SLTNode* cur = *pphead;
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	cur->next = pos->next;
	free(pos);
	pos = NULL;

}

// 删除pos之后的节点
void EraseAfter(SLTNode* pos)
{
	assert(pos && pos->next);
	SLTNode* node = pos->next;
	pos->next = pos->next->next;
	free(node);
	node = NULL;
}


// 销毁链表
void Destroy(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* pcur = *pphead;
	while (pcur)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}