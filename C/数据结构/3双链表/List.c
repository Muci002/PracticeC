#define _CRT_SECURE_NO_WARNINGS

#include "List.h"

void print(List* phead)
{
	for (List* p = phead->next; p != phead; p = p->next)
	{
		printf("%d -> ", p->data);
	}
	printf("\n");
}

// 申请新节点
List* BuyNode(ListDataType x)
{
	List* newnode = (List*)malloc(sizeof(List));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	newnode->data = x;
	newnode->prev = newnode->next = newnode;
	return newnode;
}

// 初始化
void Init(List** pphead)
{
	List* p = (List*)malloc(sizeof(List));
	if (p == NULL)
	{
		perror("malloc");
		exit(1);
	}
	p->data = -1;
	p->prev = p;
	p->next = p;

	*pphead = p;
}

// 尾插
void PushBack(List* phead, ListDataType x)
{
	assert(phead);
	List* newnode = BuyNode(x);
	newnode->prev = phead->prev;
	newnode->next = phead;
	phead->prev->next = newnode;
	phead->prev = newnode;
}

// 头插
void PustFront(List* phead, ListDataType x)
{
	assert(phead);
	List* newnode = BuyNode(x);
	newnode->prev = phead;
	newnode->next = phead->next;
	phead->next->prev = newnode;
	phead->next = newnode;
}

// 判断链表是否为空
bool Empty(List* phead)
{
	return phead == phead->next;
}

// 尾删 ** 
void PopBack(List* phead)
{
	/*assert(phead);
	List* del = phead->prev;
	phead->prev = del->prev; 
	del->prev->next = phead;
	free(del);
	del = NULL;*/
	/*assert(phead);

	List * del = phead->prev;
	del->prev->next = phead;
	phead->prev = del->prev;

	free(del);
	del = NULL;*/

	assert(phead && !Empty(phead));

	List* del = phead->prev;  // 获取尾节点
	del->prev->next = phead;  // 调整前驱节点的后继指针
	phead->prev = del->prev;  // 调整头节点的前驱指针
	free(del);

}

// 头删
void PopFront(List* phead)
{
	assert(!Empty(phead));
	List* del = phead->next;
	phead->next = del->next;
	del->next->prev = phead;
	free(del); 
}

// 查找
List* Find(List* phead, ListDataType x)
{
	assert(phead);
	for (List* p = phead->next; p != phead; p = p->next)
	{
		if (p->data == x) return p;
	}
	return NULL;
}

// 在pos之后插入数据
void Insert(List* pos, ListDataType x)
{
	assert(pos);
	List* newnode = BuyNode(x);
	newnode->next = pos->next;
	newnode->prev = pos;
	pos->next->prev = newnode;
	pos->next = newnode;
}

// 删除pos位置的节点 **
void Erase(List* pos)
{
	assert(pos);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}

// 销毁链表
void Destroy(List* phead)
{
	List* pcur = phead->next;
	while (pcur != phead)
	{
		List* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	// 销毁头节点
	free(phead);
	phead = NULL;
}