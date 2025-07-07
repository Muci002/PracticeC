//P4305 [JLOI2011] 不重复数字
#include <iostream>
#include <unordered_set>
#include <cstdio>

using namespace std;

int main()
{
	int T = 0;
	scanf("%d", &T);
	while (T--)
	{
		int n = 0;
		scanf("%d", &n);
		unordered_set<int> mp;
		
		while (n--)
		{
			int x;
			scanf("%d", &x);
			if (mp.count(x) == 0)
			{
				printf("%d ", x);
				mp.insert(x);
			}
		}
		printf("\n");
	}

	return 0;
}