//P3879
#include <iostream>
#include <unordered_set>
#include <cstdio>
#include <string>

using namespace std;

const int N = 1e3 + 10;
unordered_set<string> mp[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int l; scanf("%d", &l);
		while (l--)
		{
			string s; cin >> s;
			mp[i].insert(s);
		}
	}

	int m = 0;
	scanf("%d", &m);
	while (m--)
	{
		string s;
		cin >> s;
		bool flag = true;
		for (int i = 1; i <= n; i++)
		{
			if (mp[i].count(s))
			{
				if (flag)
				{
					printf("%d", i);
					flag = false;
				}
				else
				{
					flag = false;
					printf(" %d", i);
				}
			}
		}
		if (flag) printf("\n");
	}

	return 0;
}