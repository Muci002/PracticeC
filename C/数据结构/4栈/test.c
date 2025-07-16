#define _CRT_SECURE_NO_WARNINGS

#include "Stack.h"


int main()
{
	ST stk;
	Init(&stk);
	Push(&stk, 1);
	Push(&stk, 2);
	Push(&stk, 3);
	Push(&stk, 4);
	Push(&stk, 5);
	Push(&stk, 6);
	Push(&stk, 7);
	Push(&stk, 8);
	Push(&stk, 9);
	while (!Empty(&stk))
	{
		printf("%d ", Top(&stk));
		Pop(&stk);
	}
	return 0;
}