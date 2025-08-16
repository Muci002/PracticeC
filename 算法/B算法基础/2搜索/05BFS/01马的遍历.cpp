// P1443

 #include <iostream>
#include <queue>
#include <cstring>

using namespace std;
typedef pair<int, int> PII;
const int N = 410;
int n, m, x, y;

int dist[N][N];

// 定义方向向量
int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[] = { 2, 1, -1, -2, -2, -1, 1, 2 };

void bfs()
{
	// 初始化
	memset(dist, -1, sizeof dist);
	// 创建一个队列辅助bfs
	queue<PII> q;
	dist[x][y] = 0;
	q.push({ x, y });
	// 若队列不为空，队头节点出队并访问该节点
	while (q.size())
	{
		auto t = q.front(); q.pop();
		int i = t.first, j = t.second;
		for (int k = 0; k < 8; k++) 
		{
			int x = i + dx[k], y = j + dy[k];
			if (x < 1 || x > n || y < 1 || y > m) continue;
			if (dist[x][y] != -1) continue;
			dist[x][y] = dist[i][j] + 1;  // 更新结果
			q.push({ x, y });
		}
	}

}

int main()
{
	cin >> n >> m >> x >> y;

	bfs();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}