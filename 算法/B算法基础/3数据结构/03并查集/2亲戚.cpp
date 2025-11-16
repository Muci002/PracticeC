// P1551

// 利用并查集来维护亲戚关系

#include <iostream>

using namespace std;
const int N = 5010;
int fa[N];

int find(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

int main()
{
	int n = 0, m = 0, p = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) fa[i] = i;
	cin >> m >> p;
	while (m--)
	{
		int x = 0, y = 0;
		cin >> x >> y;
		fa[find(x)] = find(y);
	}
	while (p--)
	{
		int x = 0, y = 0;
		cin >> x >> y;
		if (find(x) == find(y))
			cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}