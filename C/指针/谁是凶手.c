//谁是凶手

#include <stdio.h>

int main()
{
	char ch[4] = { "ABCD" };
	
	
	int i = 0;
	for (; i < 4; i++)
	{
		int cnt = 0;
		//A不是我
		if (ch[i] != 'A')
		{
			cnt++;
		}
		
		//B是C
		if (ch[i] == 'C')
		{
			cnt++;
		}

		//C是D
		if (ch[i] == 'D')
		{
			cnt++;
		}

		//D不是我
		if (ch[i] != 'D')
		{
			cnt++;
		}
		if (cnt == 3)
		{
			break;
		}
	}

	printf("%c\n", ch[i]);
	return 0;
}