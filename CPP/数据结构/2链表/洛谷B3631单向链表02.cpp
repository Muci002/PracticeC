#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int e[N], ne[N], h, id, mp[N];

int main()
{
	int T = 0, op = 0, x = 0, y = 0;
	cin >> T;
	e[++id] = 1;
	ne[h] = 1;
	mp[1] = id;
	while (T--)
	{
		cin >> op >> x;
		int p = mp[x];
		if (op == 1)
		{
			cin >> y;
			e[++id] = y;
			ne[id] = ne[p];
			ne[p] = id;
			mp[y] = id;
		}
		else if (op == 2)
		{
			cout << e[ne[p]] << endl;
		}
		else
		{
             mp[e[ne[p]]] = 0;
			ne[p] = ne[ne[p]];
           
		}
	}
	return 0;
}