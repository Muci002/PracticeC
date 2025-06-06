#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int ne[N], pre[N], h, id = 1, mp[N];

int main()
{
	ne[h] = 1;
	mp[1] = 1;
	int n = 0, op = 0, x = 0, m = 0;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		cin >> x >> op;
		int p = mp[x];
		if (op)
		{
			//op == 1 右边
			++id;
			mp[i] = id;
			pre[id] = p;
			ne[id] = ne[p];
			pre[ne[p]] = id;
			ne[p] = id;
		}
		else
		{
			++id;
			mp[i] = id;
			pre[id] = pre[p];
			ne[id] = p;
			ne[pre[p]] = id;
			pre[p] = id;
		}
	}

	cin >> m;
	while (m--)
	{
		int x = 0;
		cin >> x;
		if (mp[x])
		{
			int p = mp[x];
			mp[x] = 0;
			ne[pre[p]] = ne[p];
			pre[ne[p]] = pre[p];
		}
	}

	for (int i = ne[h];i; i = ne[i])
	{
		cout << i << " ";
	}

	return 0;
}