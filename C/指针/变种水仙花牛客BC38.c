#include <stdio.h>
#include <math.h>

int cheak(int x)
{
	int n = 5;
	int sum = 0;
	
	while (n--)
	{
		int t = x;
		int a = pow(10, n);
		sum += ((t / a) * (t % a));
	}
	if (sum == x) return 1;
	return 0;
}

int main()
{

	for (int i = 10000; i < 100000;i++)
	{
		if (cheak(i))
		{
			printf("%d ", i);
		}
	}
	return 0;
}