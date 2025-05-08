#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//初始化棋盘
void initBoard(char arr[ROWS][COLS], int row, int col, char set)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = set;
		}
	}
}

//打印棋盘
void printBoard(char arr[ROWS][COLS], int row, int col)
{
	system("cls");
	printf("\n-----------------扫雷-----------------\n");
	for (int i = 0; i < col; i++) printf("%-3d ", i);
	printf("\n\n");
	for (int i = 1; i < row; i++)
	{
		printf("%-3d ", i);
		for (int j = 1; j < col; j++)
		{
			printf("%-3c ", arr[i][j]);
		}
		printf("\n\n");
	}
	printf("\n");
}


//设置随机雷
void setMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	int x = 0, y = 0;
	srand((unsigned)time(NULL));
	while (1)
	{
		printf("请输入要排查的坐标:> ");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			break;
		}
		else
		{
			printf("坐标超出范围，请重新输入\n");
		}
	}
	while (count)
	{
		int i = rand() % row + 1;
		int j = rand() % col + 1;
		if (mine[i][j] == '0' && i != x && j != y)
		{
			mine[i][j] = '1';
			count--;
		}

	}

	ExpandBlank(mine, show, x, y);

}


//计算坐标上雷的个数
int ComMine(char mine[ROWS][COLS], int x, int y)
{
	int sum = 0;
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			sum += mine[i][j] - '0';
		}
	}
	return sum;
}



//计算show上非‘*’的个数
int number(char show[ROWS][COLS], int row, int col)
{
	int cnt = 0;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (show[i][j] != '*')
			{
				cnt++;
			}
		}
	}
	return cnt;
}

//递归展开区域
void ExpandBlank(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	if (show[x][y] != '*') return;

	int count = ComMine(mine, x, y);

	if (count > 0)
	{
		show[x][y] = count + '0';
	}

	else
	{
		show[x][y] = ' ';
		for (int i = x - 1; i <= x + 1; i++)
		{
			for (int j = y - 1;j <= y + 1; j++)
			{
				if (i == x && j == y) continue;
				if (i > 0 && i < ROWS - 1 && j > 0 && j < COLS)
					ExpandBlank(mine, show, i, j);
			}
		}
	}

}

//查找雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0; 
	int win = 0;
	while (win < row * col - EASY_COUNT)
	{
		printf("请输入要排查的坐标:> ");
		scanf("%d %d", &x, &y);
		if (x >=1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printBoard(mine, ROWS - 1, COLS - 1);
				printf("----------你被炸死了----------\n----------  Defeat! ----------\n\n");
				
				break;
			}
			else if (show[x][y] != '*')
			{
				printf("此坐标已被扫过，请重新输入\n");
			}
			else
			{

				ExpandBlank(mine, show, x, y);
				
				printBoard(show, ROWS - 1, COLS - 1);
				win = number(show, ROW, COL);
				printf("win = %d\n", win);
			}
			
		}
		else
		{
			printf("坐标超出范围，请重新输入\n");
		}
	}

	if (win == row * col - EASY_COUNT)
	{
		printf("---------- 扫雷成功 ----------\n---------- Victory! ----------\n\n");
	}
	
}