#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("**************************\n");
	printf("**         菜单         **\n");
	printf("**      1.开始游戏      **\n");
	printf("**      0.退出游戏      **\n");
	printf("**************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	initBoard(mine, ROWS, COLS, '0');
	initBoard(show, ROWS, COLS, '*');

	printBoard(show, ROWS-1, COLS-1);

	setMine(mine,show, ROW, COL);
	printBoard(show, ROWS - 1, COLS - 1);
	
	FindMine(mine, show, ROW, COL);
	
}

void test()
{
	int input = 0;

	do
	{
 		menu();
		printf("请选择:> ");
		scanf("%d", &input);
		system("cls");

		switch (input)
	 	{
		case 1:
			game();
			break;

		case 0:
			printf("游戏结束\n");
			break;

		default:
			printf("选择错误！请重新选择\n\n");
			break;
		}

	} while (input);
}

int main()
{
	test();
	return 0;
}