
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10

void initBoard(char arr[ROWS][COLS], int row, int col, char set);
void printBoard(char arr[ROWS][COLS], int row, int col);
void setMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
void ExpandBlank(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);