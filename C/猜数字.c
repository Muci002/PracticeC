#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	int n = 0, x = 0;
	srand((unsigned int)time(NULL));
	int a = rand() % 100 + 1;
	do
	{
		printf("**********************\n");
		printf("**********************\n");
		printf("******  请选择  ******\n");
		printf("******  1.play  ******\n");
		printf("******  2.exit  ******\n");
		printf("**********************\n");
		printf("**********************\n\n");
		scanf("%d", &n);

		switch (n)
		{
		case 1:
			printf("请输入数字：\n");
			while (1)
			{
				scanf("%d", &x);
				if (x == a)
				{
					printf("猜对了\n");
					break;
				}
				else if (x > a)
				{
					printf("猜大了\n");
				}
				else
				{
					printf("猜小了\n");
				}
			}
			break;

		case 2:
			break;

		default:
			printf("输入错误\n");


		}

	} while (n != 2);

	return 0;
}