// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>

// #pragma pack(1)
// struct str
// {
// 	char name;
// 	int age;
// 	char he;
// };

// #pragma pack()
// struct st
// {
// 	char heh;
// 	int n;
// 	char b;
// };

// struct stu
// {
// 	int _a : 2;
// 	int _b : 4;
// 	int _c : 16;
// 	int _d : 24;
// };

// //联合体
// union Un
// {
// 	int a;
// 	char b;
// };

// //枚举
// enum En
// {
// 	RED,
// 	GREEN,
// 	BLUE
// };


// //判断大小端
// union Un
// {
//     int a;
//     char b;
// }un;

// int main()
// {
//     un.b = 1;
//     if (un.a == 1)
//     {
//         printf("小\n");
//     }
//     else
//     {
//         printf("大\n");
//     }
//     return 0;
// }


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//位段
struct A
{
	int a : 2;    //数字表示这个成员，要站用的比特位数量
	int b : 5;
	int c : 10; 
	int d : 30;
};

struct B
{
	int a;
	int b;
	int c;
	int d;
};


//联合体（共用体）成员共用一块空间
//联合体的大小至少是最大成员的大小
//当最大成员的大小不是最大对齐数的整数倍的时候，就要对齐到最大对齐数的整数倍
union Un
{
	char ch;
	int a;
};

//联合体适合使用在使用他就不使用他的场景
//比如选择奖品
struct gift_list
{
	int stock_number; //库存量
	double price;     //价格
	int item_type;    //类型

	union
	{

		struct
		{
			char title[20];   //书名
			char author[20];  //作者
			int num_pages;    //页数
		}book;

		struct
		{
			char design[30];  //设计
		}mug;

		struct
		{
			char design[30];  //设计
			int color;        //颜色
			int sizes;        //尺寸
		}shirt;

	}item;
};

//用指针判断大小端字节序
void check()
{
	int a = 1; 
	if (*(char*)&a == 1) printf("小端\n");
	else printf("大端\n");
}

//用联合体判断大小端字节序
int checks()
{
	union
	{
		char ch;
		int a;
	}Un;
	Un.a = 1;
	return Un.ch;

}

//枚举
enum Reg
{
	//枚举是常量，不能赋值，可以初始化,值默认向下递增 1
	RED = 5,
	GREEN,
	BLUE
};

int main()
{
	int len1 = sizeof(union Un);
	int len2 = sizeof(struct B);
	union Un UU;
	//printf("%d\n%d\n", len1, len2);

	//联合体共用一块空间
	//printf("%p\n%p\n%p\n", &UU, &(UU.ch), &(UU.a)); 
	UU.a = 0x11223344;
	UU.ch = 0x55;

	//地址是一个字节一个字节分配的，所以不能对联合体的成员直接进行修改，可以借助其他变量进行修改
	/*char c;
	scanf("%c", &c);
	UU.ch = c;
	printf("%c\n", c);*/

	//cheak();
	

	
	/*if (checks() == 1)
	{
		printf("小端\n");
	}
	else printf("大端\n");*/

	/*printf("%d\n", RED);
	printf("%d\n", GREEN);
	printf("%d\n", BLUE);*/

	//RED = 7; //err

	enum Reg color = RED;

	if (color == RED) 
		printf("红\n");
	else if (color == GREEN) 
		printf("绿\n");
	else 
		printf("蓝\n");
		
	return 0;
}