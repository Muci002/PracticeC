#define _CRT_SECURE_NO_WARNINGS

#include "SeqList.h"

//打印
void print(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

//初始化
void init(SL *ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

// 检查是否需要扩容
void SLCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLTDataType* tmp = (SLTDataType*)realloc(ps->arr, newcapacity * sizeof(SLTDataType));
		if (tmp == NULL)
		{
			perror("realloc");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
}

// 尾插
void push_back(SL* ps, SLTDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	ps->arr[ps->size++] = x;
}

// 头插
void push_front(SL* ps, SLTDataType x)
{
	assert(ps);
	SLCheckCapacity(ps); //检查空间是否足够
	for (int i = ps->size - 1; i > 0; i++)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	ps->size++;
}

// 尾删
void pop_back(SL* ps)
{
	// 检查顺序表是否还有元素
	assert(ps && ps->size);
	ps->size--;
}

// 头删
void pop_front(SL* ps)
{
	assert(ps && ps->size);
	for (int i = 0; i < ps->size; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

// 查找
int find(SL* ps, SLTDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x) return i;
	}
	return -1;
}

// 指定位置之前插入
void insertpre(SL* ps, int pos, SLTDataType x)
{
	assert(ps);
	// 判断插入位置是否合法
	assert(pos >= 0 && pos < ps->size);
	SLCheckCapacity(ps);
	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = x;
	ps->size++;
}

// 删除 pos 位置的数据
void erase(SL* ps, int pos, SLTDataType x)
{
	assert(ps);
	// 判断pos是否合法
	assert(pos >= 0 && pos < ps->size);
	for (int i = pos; i < ps->size - 1; i++)
	{
		*(ps->arr + i) = *(ps->arr + i + 1);
	}
	ps->size--;
}