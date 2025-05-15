#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>

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