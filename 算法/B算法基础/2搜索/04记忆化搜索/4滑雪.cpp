// P1434

#include <iostream>
#include <cmath>
using namespace std;
const int N = 101;
int a[N][N];
int n, m;
int f[N][N];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

int dfs(int i, int j)
{
	if (f[i][j]) return f[i][j];
	int ret = 1;
	for (int k = 0; k < 4; k++)
	{
		int x = i + dx[k], y = j + dy[k];
		if (x > n || x < 1 || y > m || y < 1) continue;
		if (a[i][j] <= a[x][y]) continue;
		ret = max(ret, dfs(x, y) + 1);
	}
	return f[i][j] = ret;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}

	int ret = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			ret = max(ret, dfs(i, j));
		}
	}
	cout << ret;
	return 0;
}