#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

//交换
void Swap(void* a, void* b, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		char ch = *((char*)a+i);
		*((char*)a+i) = *((char*)b+i);
		*((char*)b+i) = ch;
	}
}

//可以排任意类型数组的冒泡排序
void Sort(void* base, size_t len, size_t size, int (*pf)(const void*, const void*))
{
	for (int i = 0; i < len; i++)
	{
		int flag = 1;
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (pf((char*)base + size * j, (char*)base + size * (j + 1)) > 0)
			{
				Swap((char*)base + size * j, (char*)base + size * (j + 1), size);
				flag = 0;
			}
		}
		if (flag) break;
	}
}

//打印整形数组
void Print(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n\n");
}

//打印结构体数组
void Print2(struct stu* s, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%s : %d\n", (s + i)->name, s[i].age);
	}
}

//比较整形数组
int Comp(const void* a, const void* b)
{
	return *((int*)a) - *((int*)b);
}

//比较结构体数组
int Comp2(const void* a, const void* b)
{
	return strcmp((char*)a, (char*)b);
}

struct stu
{
	char name[20];
	int age;
};

int main()
{
	int arr[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Sort(arr, len, sizeof(arr[0]), Comp);
	Print(arr, len);

	struct stu s[3] = { {"zhangshan", 18}, {"lishi", 16}, {"wangwu", 20} };
	int len2 = sizeof(s) / sizeof(s[0]);
	Sort(s, len2, sizeof(s[0]), Comp2);
	Print2(s, len2);

	return 0;
}