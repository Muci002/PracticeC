#include <stdio.h>
#include <stdbool.h>
bool Leap(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
	{
		return true;
	}
	else if (year % 400 == 0)
		return true;
	return false;
}

int Count(int year, int mounth)
{
	int day[13] = { 0, 31, 28, 31,30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (mounth == 2)
	{
		if (Leap(year))
		{
			return 29;
		}
	}
	return day[mounth];
}

int main()
{

	int year = 0, mounth = 0;
	while (scanf("%d %d", &year, &mounth) != EOF)
	{
		int day = Count(year, mounth);
		printf("%d\n", day);
	}
	return 0;
}