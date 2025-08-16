// NC50041

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
typedef pair<int, int > PII;
const int N = 33;
char a[N][N];
int n, m, x, y;
vector<int> tmp;
int dist[N][N];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

void bfs()
{
	memset(dist, -1, sizeof dist);
	queue<PII> q;
	q.push({ x, y });
	dist[x][y] = 0;
	
	while (q.size())
	{
		PII t = q.front();q.pop();
		int i = t.first, j = t.second;
		for (int k = 0; k < 4; k++)
		{
			int x = i + dx[k], y = j + dy[k];
			if (a[x][y] == '*' || x < 1 || x > n || y < 1 || y > m) continue;
			if (dist[x][y] != -1) continue;
			
			if (a[x][y] == 'e')
			{
				tmp.push_back(dist[i][j] + 1);
                dist[x][y] = dist[i][j] + 1;
				continue;
			}
			dist[x][y] = dist[i][j] + 1;
			q.push({ x, y });
		}
	}

}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'k')
				x = i, y = j;
		}
	}

	bfs();
	if (tmp.size() == 0) cout << -1;
	else
	{
		sort(tmp.begin(), tmp.end());
		cout << tmp.size() << " " << tmp[0];
	}

	return 0;
}