#include <stdio.h>

#define MAX(x,y) ( (x) > (y) ? (x) : (y) )

int main()
{
	int a = 10;
	int b = 20;
	int c = MAX(a, b);
	printf("%d\n", c);

	return 0;
}