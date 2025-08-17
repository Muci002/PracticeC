// NC51024


#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;
const int N = 1010;
int a[N][N];
int dist[N][N];
int n, m;
queue<PII> q;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

void bfs()
{
	while (q.size())
	{
		PII t = q.front(); q.pop();
		int i = t.first, j = t.second;
		for (int k = 0; k < 4; k++)
		{
			int x = i + dx[k], y = j + dy[k];
			if (x < 1 || x > n || y < 1 || y > m) continue;
			if (dist[x][y] != -1 && dist[x][y] <= dist[i][j] + 1) continue;
			dist[x][y] = dist[i][j] + 1;
			q.push({ x, y });
		}
	}
}

int main()
{
	memset(dist, -1, sizeof dist);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char ch; cin >> ch;
			a[i][j] = ch - '0';
			if (a[i][j])
			{
				dist[i][j] = 0;
				q.push({ i, j });
			}
		}
	}

	bfs();

	for (int i = 1; i <= n;i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}