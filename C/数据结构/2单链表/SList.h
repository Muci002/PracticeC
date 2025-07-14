#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDatatype;

// 链表结构
typedef struct SListNode
{
	SLDatatype data;
	struct SListNode* next;
}SLTNode;

// 打印
void print(SLTNode* slt);

// 尾插
void SLTPushBack(SLTNode** pphead, SLDatatype x);

// 头插
void SLTPushFront(SLTNode** pphead, SLDatatype x);

// 尾删
void SLTPopBack(SLTNode** pphead);

// 头删
void SLTPopFront(SLTNode** pphead);

// 查找
SLTNode* Find(SLTNode* phead, SLDatatype x);

// 在指定位置之前插入数据
void InsertFront(SLTNode** pphead, SLTNode* pos, SLDatatype x);

// 在指定位置之后插入数据
void InsertBack(SLTNode* pos, SLDatatype x);

// 删除pos节点
void Erase(SLTNode** pphead, SLTNode* pos);

// 删除pos之后的节点
void EraseAfter(SLTNode* pos);


// 销毁链表
void Destroy(SLTNode** pphead);
