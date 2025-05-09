#include <stdio.h>
#define N 10

typedef struct 
{
	int first; 
	int second;
}Pair;

//杨氏三角
void Yanshi(int (*pa)[N], int row, int col)
{
	int count = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			pa[i][j] = ++count;
		}
	}
}

void Print(int (*pa)[N], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%-2d ", pa[i][j]);
		}
		printf("\n");
	}
}

//查找
Pair Find(int (*arr)[N], int row, int col, int n)
{
	Pair p;
	int x = 0;
	for (int i = 0; i < row; i++)
	{
		if (n <= arr[i][col - 1])
		{
			p.first = i;
			x = i;
			break;
		}
	}


	int l = 0, r = col - 1, mid = 0;
	while (l < r)
	{
		mid = (l + r) / 2;
		if (arr[x][mid] < n) l = mid+1;
		else r = mid;
	}
	if (arr[x][l] == n)
		p.second = l;
	else
		p.second = -1;
	return p;
}


int main()
{
	int n = 0;
	int arr[N][N] = { 0 };

	Yanshi(arr, N, N);
	Print(arr, N, N);

	scanf("%d", &n);
	Pair dess= Find(arr, N, N, n);
	printf("%d %d", dess.first, dess.second);

	return 0;
}