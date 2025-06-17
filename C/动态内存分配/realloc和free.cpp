#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{

	// void* ralloc(void *ptr, size_t size)
	//ptr是要调整的内存地址，size 是调整之后的新大小单位是字节
	//反回调整之后内存空间的起始地址
	//这个函数在调整原内存空间大小的基础上，还会将原内存中的数据移动到新的空间
	//ptr 需要是动态内存开辟的


	//先用 malloc 开辟一块空间
	int len = 5;
	int* p = (int*)malloc(len * sizeof(int));

	//判断 malloc 的返回值
	assert(p);

	for (int i = 0; i < len; i++)
	{
		p[i] = i + 1;
	}

	//用 realloc 修改大小、因为ralloc可能开辟失败，所以不能直接赋值给原指针
	// realloc 在调整内存空间存在两种情况
	//1.原有空间之后有足够大的空间 : 直接在原有空间后面开辟，原有空间的数据不会发生变化，返回原有空间的地址
	//2.原有空间之后没有足够大的空间 ：
	// 1 重新找一个新的空间。
	// 2 将旧的空间的数据拷贝一份到新的空间。
	// 3 释放旧的空间
	// 4 返回新的空间的地址
	int len2 = 10;
	int p2 = (int*)realloc(p, len2 * sizeof(int));
	//检查返回值
	assert(p2);

	//释放
	//free只能释放动态开辟的空间，并且一定要是这块空间的起始地址
	//不能对一块空间进行多次释放 
	//如果给 free 传空指针，free什么都不做
	free(p2);  
	p2 = NULL;

	// realloc 也可以直接用来开辟空间
	int* p3 = (int*)realloc(NULL, 40); // 等价于 malloc(40)


	return 0;
}