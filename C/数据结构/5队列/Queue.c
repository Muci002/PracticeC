#define _CRT_SECURE_NO_WARNINGS

#include "Queue.h"

// 判断队列是否为空
bool Empty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL;
}

// 初始化
void Init(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

// 入队列
void Push(Queue* pq, Datatype x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;
	// 队列为空
	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}

// 出队列
void Pop(Queue* pq)
{
	assert(pq);
	// 只有一个元素
	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		QueueNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	pq->size--;
}

// 取队头数据
Datatype Top(Queue* pq)
{
	assert(!Empty(pq));
	return pq->phead->data;
}

// 取队尾数据
Datatype Back(Queue* pq)
{
	assert(!Empty(pq));
	return pq->ptail->data;
}

// 返回队列有效元素个数
int Size(Queue* pq)
{
	assert(pq);
	return pq->size;
}

// 销毁
void Destroy(Queue* pq)
{
	assert(pq);
	QueueNode* pcur = pq->phead;
	while (pcur)
	{
		QueueNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}