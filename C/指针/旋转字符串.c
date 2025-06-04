#include <stdio.h>
#include <stdbool.h>

bool Com(char* a, char* b)
{
	for (int i = 0; a[i] != '\0'; i++)
	{
		if (a[i] != b[i])
		{
			return false;
			
		}
	}
	return true;
}

int Turn(char* ch1, char* ch2, int len)
{
	
	for (int i = 0; i < len; i++)
	{
		if (Com(ch1, ch2))
		{
			return 1;
		}
		else
		{
			ch2[len] = ch2[0];
			for (int j = 0; j <= len; j++)
			{
				ch2[j] = ch2[j + 1];
				
			}
		}
	}
	return 0;
}

int main()
{
	char ch1[10];
	char ch2[10];
	scanf("%s %s", ch1, ch2);

	int len = strlen(ch1);
	int n = Turn(ch1, ch2, len);
	printf("%d\n", n);


	return 0;
}