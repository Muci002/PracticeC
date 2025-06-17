#include <stdio.h>
#include <stdlib.h>

int main()
{
	// void* malloc(size_t size)
	//动态内存开辟
	//size要申请内存空间的大小字节
	//开辟成功，返回这块空间的起始地址
	//开辟失败，返回一个 NULL 的空指针，因此 malloc 的返回值一定要做检查

	int* p = (int*)malloc(5 * sizeof(int));
	
	//检查malloc的返回值
	if (p == NULL)
	{
		perror("malloc");
		return 0;
	}

	for (int i = 0; i < 5; i++)
	{
		p[i] = i + 1;
	}
	/*for (int i = 0; i < 5; i++)
	{
		printf("%d  ", *(p + i));
	}*/

	// void free( void* ptr )
	// 回收和释放动态内存
	//如果 ptr 指向的空间不是动态内存开辟的，那么 free 的行为是未定义的
	//如果参数 ptr 是空指针，则函数什么事都不做

	free(p);
	// free 不会把指针置为空，需要手动把指针置为空
	p = NULL;

	// void* calloc( size_t num, size_t size)
	// 为 num 个大小为 size 的元素开辟一块空间，并把空间每个字节初始化为 0

	/*int* pc = (int*)calloc(10, sizeof(int));

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", pc[i]);
	}*/




	return 0;
}


