#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


// 定义队列节点
typedef int Datatype;
typedef struct QueueNode
{
	Datatype data;
	struct QueueNode* next;
}QueueNode;

// 定义队列结构
typedef struct Queue
{
	QueueNode* phead;
	QueueNode* ptail;
	int size;
}Queue;



// 初始化
void Init(Queue* pq);
// 入队列
void Push(Queue* pq, Datatype x);
// 出队列
void Pop(Queue* pq);
// 判断队列是否为空
bool Empty(Queue* pq);
// 取队头数据
Datatype Top(Queue* pq);
// 取队尾数据
Datatype Back(Queue* pq);
// 返回队列有效元素个数
int Size(Queue* pq);
// 销毁
void Destroy(Queue* pq);