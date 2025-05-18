#define _CRT_SECURE_NO_WARNINGS

#define NDEBUG

#include <stdio.h>
#include <string.h>
#include <assert.h>

//求字符串长度
size_t MyStrLen(const char* str)
{
	assert(str != NULL); //防止传入空指针
	int ret = 0; 
	while (*str)
	{
		str++;
		ret++;
	}
	return ret;
}


//拷贝字符串
char* MyStrCpy(char* str1, const char* str2)
{
	assert(str1 && str2);
	char* ret = str1;
	while (*str1++ = *str2++);
	
	return ret;
}

//拷贝指定长度字符串
char* MyStrnCpy(char* str1, const char* str2, int num)
{
	assert(str1 && str2);
	char* ret = str1;
	while (num--)
	{
		*str1++ = *str2++;
		if (!*str2) break;
	}
	while (num--)
	{
		*str1++ = '\0';
	}
	return ret;
}

//链接字符串
char* MyStrCat(char* str1, const char* str2)
{
	assert(str1 && str2);
	char* ret = str1;
	while (*str1)
	{
		str1++;
	}
	
	while(*str1++ = *str2++);
	return ret;
}

//链接指定长度
char* MyStrnCat(char* str1, const char* str2, size_t num)
{
	assert(str1 && str2);
	char* ret = str1;

	while (*str1)
	{
		str1++;
	}

	while (num--)
	{
		if (!*str2)
		{
			break;
		}
		*str1++ = *str2++;
	}

	*str1 = '\0';

	return ret;
}

int main()
{
	char str1[] = "How\0hhhh";
	char str2[10] = "*********";
	char* p = MyStrnCpy(str2, str1,6);

 	printf("%s\n", p);
	printf("%s\n", str2);
	printf("%s\n", MyStrnCpy(str2, str1, 6));
	return 0;
}

