#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// 定义栈的结构
typedef int DataType;
typedef struct Stack
{
	DataType* arr;
	int top;   // 栈顶
	int capacity;
}ST;


// 初始化
void Init(ST* stk);
// 销毁
void DesTroy(ST* stk);
// 入栈
void Push(ST* stk, DataType x);
// 出栈
void Pop(ST* stk);
// 返回栈顶元素
DataType Top(ST* stk);
// 栈是否为空
bool Empty(ST* stk);
// 获取有效元素个数
int Size(ST* stk);