#define _CRT_SECURE_NO_WARNINGS

#include "Queue.h"


int main()
{
	Queue q;
	Init(&q);
	Push(&q, 1);
	Push(&q, 2);
	Push(&q, 3);
	Push(&q, 4);
	Push(&q, 5);
	Push(&q, 6);
	Push(&q, 7);
	Push(&q, 8);
	Push(&q, 9);
	while (Size(&q))
	{
		printf("%d ", Top(&q));
		Pop(&q);
	}
	return 0;
}