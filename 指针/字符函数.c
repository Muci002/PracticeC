#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* my_strcpy(char* dest, char* str)
{
	char* ret = dest;
	assert(dest != NULL);
	while (*dest++ = *str++);

	return ret;
}

char* my_strcat(char* dest, char* str)
{
	assert(dest && str);
	char ret = dest;
	while (*dest != '\0')
		dest++;
	while (*dest++ = *str++)
	{
		;
	}

	return ret;

}

int my_strlen(const char* dest)
{
	assert(dest != NULL);
	int ret = 0;
	while (*dest != '\0')
	{
		dest++;
		ret++;
	}
	return ret;
}

int main()
{
	char arr[] = "is big";
	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (islower(arr[i]))
		{
			arr[i] = toupper(arr[i]);
		}
	}
	
	strcpy(ch, arr);

	printf("%s\n", arr);
	printf("%s\n", arr);
	return 0;
}