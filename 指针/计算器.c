#define _CRT_SECURE_NO_WARNINGS

#define NDBUG

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// //求字符串长度
//  size_t MyStrlen(const char* arr)
// {
// 	int count = 0;
	
// 	assert(arr != NULL);

// 	for (int i = 0; arr[i] != '\0'; i++)
// 	{
// 		count++;
// 	}

// 	return count;
// }

// //交换a和b的值，传址调用
//  void Swap(int *a, int* b)
//  {
// 	 int c = *a; 
// 	 *a = *b;
// 	 *b = c;
//  }

// int main()
// {
// 	char arr[10] = "abcdef";
// 	int len = MyStrlen(arr);
// 	printf("%d\n", len);

// 	int a = 2, b = 3;
// 	printf("%d %d\n", a, b);

// 	return 0;
// }

//加法
int Add(int a, int b)
{
	return a + b;
}

//减法
int Sub(int a, int b)
{
	return a - b;
}

//乘法
int Mul(int a, int b)
{
	return a * b;
}

//除法
int Divi(int a, int b)
{
	return a / b;
}

//计算器
int Calc(int (*pf) (int, int))
{
	int a, b;
	printf("请输入两个数：\n");
	scanf("%d %d", &a, &b);
	return pf(a, b);
}


int main()
{
	int input = 0;
	do
	{
		
		printf("-----------------请选择---------------\n");
		printf("1.加法  2.减法  3.乘法  4.除法  0.退出\n\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			printf("%d\n\n", Calc(Add));
			break;
		case 2:
			system("cls");
			printf("%d\n\n", Calc(Sub));
			break;
		case 3:
			system("cls");
			printf("%d\n\n", Calc(Mul));
			break;
		case 4:
			system("cls");
			printf("%d\n\n", Calc(Divi));
			break;
		case 0:
			system("cls");
			printf("结束");
			break;
		default:
			system("cls");
			printf("输入错误，请重新输入\n\n ");
			break;

		}

	} while (input);
	return 0;
}