#include <stdio.h>
#include <stdbool.h>

int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 6 };
	
	int x = 0, y = 0;
	
	for (int i = 0; i < 10; i++)
	{
		bool falg = true;
		for (int j = i+1; j < 10; j++)
		{
			if (arr[i] == arr[j])
			{
				falg = false;
				break;
			}
		}
		if (falg && y)
		{
			x = arr[i];
		}
		else if (falg)
		{
			y = arr[i];
		}

	}

	printf("%d %d\n", x, y);

	return 0;
}