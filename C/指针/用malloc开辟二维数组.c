#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* p = malloc(sizeof(int) * 3 * 5);
	int(*pp)[5] = p;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			pp[i][j] = j;
			printf("%d ", pp[i][j]);
		}
		printf("\n");
	}
	return 0;
}