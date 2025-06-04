//杨辉三角

#define N 12
#include <stdio.h>

void YanHui(int (*pa)[N], int row, int col)
{
	pa[0][1] = 1;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= i+1; j++)
		{
			pa[i][j] = pa[i - 1][j - 1] + pa[i - 1][j];
		}
	}
}

void Print(int (*pa)[N], int row, int col)
{
	for(int i = 0; i <= row; i++)
	{
		for (int j = 1; j <= i + 1; j++)
		{
			printf("%d ", pa[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int arr[N][N] = {0};

	YanHui(arr, 10, 10);

	Print(arr, 10, 10);

	return 0;
}