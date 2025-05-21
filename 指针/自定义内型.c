#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#pragma pack(1)
struct str
{
	char name;
	int age;
	char he;
};

#pragma pack()
struct st
{
	char heh;
	int n;
	char b;
};

struct stu
{
	int _a : 2;
	int _b : 4;
	int _c : 16;
	int _d : 24;
};


int main()
{
	printf("%zd\n",sizeof(struct stu));
	return 0;
}