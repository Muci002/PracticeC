#include <stdio.h>
#include <stdlib.h>

//柔性数组
//结构体中的柔性数组成员前面必须至少有一个其他成员
//sizeof返回这种结构大小不包括柔性数组的内存
//包含柔性数组成员的结构用 malloc() 函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应柔性数组的的预期大小
//
struct st_type
{
	int n;
	int a[];  //柔性数组成员
};

struct S
{
	int m;
	int* pa;    //用指针达到柔性数组的效果
};

int main()
{
	struct st_type* p = (struct st_type*)malloc(sizeof(struct st_type) + 10 * sizeof(int));//给柔性数组分配空间

	//判断malloc的返回值
	if (p == NULL)
	{
		perror("malloc");
		return 1;
	}

	p->n = 100;

	printf("%d\n", p->n);

	for (int i = 0; i < 10; i++)
	{
		p->a[i] = i + 1;
	}

	/*for (int i = 0; i < 10; i++)
	{
		printf("%d  ", p->a[i]);
	}*/

	//调整空间
	struct st_type* tmp = (struct st_tmp*)realloc(p, sizeof(struct st_type) + 20 * sizeof(int));
	//判断realloc的放回值
	if (tmp == NULL)
	{
		perror("realloc");
		return 1;
	}

	p = tmp;

	//释放
	free(p);
	p = NULL;


	//用指针达到柔性数组的效果
	struct S* ps = (struct S*)malloc(sizeof(struct S));
	if (ps == NULL)
	{
		perror("malloc");
		return 1;
	}

	int* parr = (int*)malloc(sizeof(int) * 10);
	if (parr == NULL)
	{
		perror("malloc pa");
		return 1;
	}

	ps->pa = parr;
	for (int i = 0; i < 10; i++)
	{
		ps->pa[i] = i + 2;
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d  ", ps->pa[i]);
	}

	//释放
	free(ps->pa);
	free(ps);
	ps = NULL;
	return 0;
}