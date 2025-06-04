#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
typedef int (*pa)[5];

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

//利用指针打印二维数组
void Print2(int (*p)[5], int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", *(*(p + i) + j));
			/*printf("%d ", p[i][j]);*/
			/*printf("%d ", (*(p + i))[j]);*/
			/*printf("%d ", *(p[i] + j));*/
		}
		printf("\n");
	}
}

int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* p = arr;
	int len = sizeof(arr) / sizeof(arr[0]);
	Print1(p, len);

	int arr2[3][5] = { {1, 2, 3, 4, 5}, {2, 3, 4, 5, 6}, {3, 4, 5, 6, 7} };
	pa p2 = arr2;
	Print2(p2, 3);

	return 0;
}