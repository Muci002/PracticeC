#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// 定义动态顺序表的结构
typedef int SLTDataType;
typedef struct SeqList
{
	SLTDataType* arr; // 存储数据
	int size;         // 有效元素的个数 
	int capacity;     // 顺序表的大小
}SL;

// 扩容
void SLCheckCapacity(SL* ps);
// 初始化
void init(SL* ps);
// 尾插
void push_back(SL* ps, SLTDataType x);
// 头插
void push_front(SL* ps, SLTDataType x);

void print(SL* ps);

// 尾删
void pop_back(SL* ps);

// 头删
void pop_front(SL* ps);

// 查找
int find(SL* ps, SLTDataType x);


// 指定位置之前插入
void insertpre(SL* ps, int pos, SLTDataType x);
// 删除 pos 位置的数据
void erase(SL* ps, int pos, SLTDataType x)