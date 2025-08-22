// P3367

#include <iostream>

using namespace std;
const int N = 1e6 + 10;

int n;
int fa[N];

int find(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

int main()
{
	int m; cin >> n >>m;
	for (int i = 1; i <= n; i++) fa[i] = i;
	while (m--)
	{
		int z = 0; cin >> z;
		int x = 0, y = 0; cin >> x >> y;
		if (z == 1)
		{
			fa[find(x)] = find(y);
		}
		else
		{
			if (find(x) == find(y)) cout << 'Y' << endl;
			else cout << 'N' << endl;
		}
	}

	return 0;
}