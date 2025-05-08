#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

//利用指针打印一维数组
void Print1(int* p, int len)
{
	for (int i = 0; i < len; i++)
	{
		/*printf("%d ", p[i]);*/
		printf("%d ", *(p + i));
	}
	printf("\n\n");
}

//交换
void Swap(int* a, int* b)
{
	int c = *a; 
	*a = *b;
	*b = c;
}

//比较
bool Comp(int a, int b)
{
	return a > b;
}

//冒泡排序
void Sort(int *p, int len, bool (*com)(int, int))
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (com(*(p+j),*(p+j+1)))
			{
				Swap((p + j), (p + j + 1));
			}
		}
	}
}

int main()
{
	int arr[10] = { 3, 2, 5, 6, 1, 7, 3, 9, 8, 0 };

	int len = sizeof(arr) / sizeof(arr[0]);
		Sort(arr, len, Comp);

		Print1(arr, len);

	return 0;
}