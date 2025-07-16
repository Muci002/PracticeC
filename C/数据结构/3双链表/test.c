#define _CRT_SECURE_NO_WARNINGS

#include "List.h"

int main()
{
	List* plist = NULL;
	Init(&plist);
	PushBack(plist, 1);
	PushBack(plist, 2);
	PushBack(plist, 3);
	PushBack(plist, 4);
	PushBack(plist, 5);
	PushBack(plist, 6);
	PushBack(plist, 7);
	print(plist);
	/*if (Find(plist, 5) != NULL) printf("yes");
	else printf("no");*/
	Insert(Find(plist, 4), 9);
	print(plist);
	/*while (!Empty(plist))
	{
		PopFront(plist);
		print(plist);
	}
	PopFront(plist);
	print(plist);*/

	/*Erase(Find(plist, 4));
	print(plist);*/

	PopBack(plist);
	print(plist);

	return 0;
}