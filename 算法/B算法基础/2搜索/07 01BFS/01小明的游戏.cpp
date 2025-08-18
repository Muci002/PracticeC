// P4554

#include <iostream>
#include <deque>
#include <cstring>

using namespace std;
typedef pair<int, int> PII;
const int N = 510;

char a[N][N];
int n, m;
int x1, y9;
int x2, y2;
int dist[N][N];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int bfs()
{
	memset(dist, -1, sizeof dist);
	deque<PII> q;
	q.push_back({ x1, y9 });
	dist[x1][y9] = 0;

	while (q.size())
	{
		PII t = q.front(); q.pop_front();
		int i = t.first, j = t.second;
        if(i== x2 && j == y2) return dist[i][j];
		for (int k = 0; k < 4; k++)
		{
			int x = i + dx[k], y = j + dy[k];
			if (x < 0 || x >= n || y < 0 || y >= m) continue;
			int w = 0;
			if (a[i][j] != a[x][y]) w = 1;
			if(dist[x][y] == -1)
			{
				if (w == 0)
				{
					q.push_front({ x, y });
				}
				else q.push_back({ x, y });
				dist[x][y] = dist[i][j] + w;
			}
			else if (dist[x][y] > dist[i][j] + w ) // 虽然是第二次遇到，但是这种情况更优
			{
                // 松弛操作
				q.push_front({ x, y });
				dist[x][y] = dist[i][j] + w;
			}
		}
	}
	return dist[x2][y2];
}

int main()
{
	while(cin >> n >> m)
	{
		if (n == 0 && m == 0) break;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> a[i][j];
			}
		}
		cin >> x1 >> y9 >> x2 >> y2;
		cout << bfs() << endl;
		
	}
	return 0;
}