#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//#define SQUARE(x) x * x
#define SQUARE(x) ((x) + (x));
//用于对数值表达式进行求值的宏定义都应该用这种方式加上括号，避免在使用宏时由于参数中的操作符和邻近操作符之间不可预料的相互作用

//求两个数的最大值的宏
#define MAX(a,b) ((a) > (b) ? (a) : (b));

//宏可以传类型
#define MALLOC(n, type) (type*)malloc(n * sizeof(type));

// # 运算符将宏的一个参数转换为字符串字面量，它仅允许出现在带参数的宏的替换列表中
// # 运算符所进行的操作可以理解为 "字符串化"
#define PRINT(n, format) printf("the value of "#n" is " format"\n", n);

// ## 可以把位于它两边的符号合成一个符号，它允许宏定义从分离的文本片段创建标识符
// ## 被称为记号联合，这样的连接必须产生一个合法的标识符，否则其结果就是未定义的

//这个宏是一个生成函数的模板
#define GENERIC_MAX(type) \
type type##_max(type x, type y)\
{\
	return x > y ? x : y;\
}

//int int_max(int x, int y)
//{
//	return x > y ? x : y;
//}
GENERIC_MAX(int);

// #undef 这条命令用于移除一个宏定义
#define M 100
#undef M

int main()
{
	int a = 10;
	//int f = SQUARE(a);
	//int f = SQUARE(a + 1);  // 宏的参数不会进行计算，直接替换到宏体内
	//printf("%d\n", f);
	int b = 12;
	int maxValue = int_max(a, b);
	printf("%d\n", maxValue);

	//给宏传类型
	/*int* p = MALLOC(10,int);

	if (p == NULL)
	{
		perror("malloc");
		return 1;
	}

	free(p);
	p = NULL;*/

	//PRINT(a, "%d");

	return 0;
}