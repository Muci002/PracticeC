#define _CRT_SECURE_NO_WARNINGS

#include "SeqList.h"

int main()
{
	SL sl;

	init(&sl);
	push_back(&sl, 1);
	push_back(&sl, 2);
	push_back(&sl, 3);
	push_back(&sl, 4);
	push_back(&sl, 5);
	print(&sl);
	/*pop_back(&sl);
	print(&sl);
	pop_front(&sl);
	print(&sl);*/

	int b = find(&sl, 4);
	printf("%d\n", b);

	insertpre(&sl, 1, 100);
	print(&sl);

	erase(&sl, 1);
	print(&sl);

	return 0;
}