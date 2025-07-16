#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


// 创建双向链表
typedef int ListDataType;
typedef struct ListNode
{
	ListDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}List;

// 申请新节点
List* BuyNode(ListDataType x);

// 初始化
void Init(List** pphead);

// 在双向链表中增删查改都不会改变哨兵节点位置
// 尾插
void PushBack(List* phead, ListDataType x);
// 头插
void PustFront(List* phead, ListDataType x);

// 判断链表是否为空
bool Empty(List* phead);
// 打印
void print(List* phead);
// 尾删
void PopBack(List* phead);
// 查找
List* Find(List* phead, ListDataType x);
// 在pos之后插入数据
void Insert(List* pos, ListDataType x);
// 删除pos位置的节点 **
void Erase(List* pos);
// 销毁链表
void Destroy(List* phead);