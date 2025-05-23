#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <assert.h>

//拷贝任意类型
void* MyMemCpy(void* p1, void* p2, size_t num)
{
	assert(p1 && p2);
	char* cur1 = (char*)p1;
	char* cur2 = (char*)p2;
	while (num--)
	{
		*cur1++ = *cur2++;
	}
	return p1;
}

//内存重叠的拷贝
void* MyMemMove(const void* p1, const void* p2, size_t num)
{
	assert(p1 && p2);
	char* cur1 = (char*)p1;
	char* cur2 = (char*)p2;
	if (p2 <= p1) //后 -> 前
	{
		while (num--)
		{
			*(cur1 + num) = *(cur2 + num);
		}
	}
	else
	{
		while (num--)
		{
			*cur1++ = *cur2++;
		}
	}
	return p1;
}

int main()
{
	char arr1[] = "abcdef";
	char arr2[10] = { 0 };
	MyMemCpy(arr2, arr1,5);
 	return 0;
}