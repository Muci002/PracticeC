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

//联合体
union Un
{
	int a;
	char b;
};

//枚举
enum En
{
	RED,
	GREEN,
	BLUE
};


//判断大小端
union Un
{
    int a;
    char b;
}un;

int main()
{
    un.b = 1;
    if (un.a == 1)
    {
        printf("小\n");
    }
    else
    {
        printf("大\n");
    }
    return 0;
}
