#define _CRT_SECURE_NO_WARNINGS

#include "Stack.h"


// 检查空间是否足够
void Check(ST* stk)
{
	if (stk->top < stk->capacity) return;
	int newcapacity = stk->capacity == 0 ? 4 : 2 * stk->capacity;
	ST* tmp = (ST*)realloc(stk->arr, newcapacity * sizeof(DataType));
	if (tmp == NULL)
	{
		perror("realloc ");
		exit(1);
	}
	stk->arr = tmp;
	stk->capacity = newcapacity;
}

// 初始化
void Init(ST* stk)
{
	stk->arr = (ST*)malloc(4 * sizeof(DataType));
	stk->top = 0;
	stk->capacity = 4;
}

// 销毁
void DesTroy(ST* stk)
{
	if (stk->arr) free(stk->arr);
	stk->arr = NULL;
	stk->top = stk->capacity = 0;
}

// 入栈
void Push(ST* stk, DataType x)
{
	assert(stk);
	Check(stk);
	stk->arr[stk->top++] = x;
}

// 出栈
void Pop(ST* stk)
{
	assert(stk);
	stk->top--;
}

// 返回栈顶元素
DataType Top(ST* stk)
{
	assert(stk);
	return stk->arr[stk->top - 1];
}

// 栈是否为空
bool Empty(ST* stk)
{
	assert(stk);
	return stk->top == 0;
}

// 获取有效元素个数
int Size(ST* stk)
{
	assert(stk);
	return stk->top;
}