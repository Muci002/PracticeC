// P1902

// 二分答案 + 判断
// 伤害值不超过 mid 的情况，能否找到一条到达第 n 行的路线

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 1010;
typedef pair<int, int> PII;

int a[N][N];
int n, m;
bool dist[N][N];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

bool bfs(int p)
{
	if (n == 1) return true;
	memset(dist, 0, sizeof dist);
	queue<PII> q;

	for (int i = 1; i <= m; i++)
	{
		q.push({ 1, i });
		dist[1][i] = true;
	}

	while (q.size())
	{
		PII t = q.front(); q.pop();
		int i = t.first, j = t.second;
		for (int k = 0; k < 4; k++)
		{
			int x = i + dx[k], y = j + dy[k];
			if (x < 1 || x > n || y < 1 || y > m) continue;
			if (dist[x][y]) continue;
			if (a[x][y] > p) continue;
			dist[x][y] = true;
			q.push({ x, y });
			if (x == n) return true;
		}
	}
	return false;

}

int main()
{
	int l = 0, r = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			r = max(r, a[i][j]);
		}
	}

	while (l < r)
	{
		int mid = (l + r) / 2;
		if (bfs(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l;

	return 0;
}