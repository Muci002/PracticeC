// P1596

// FloodFill算法，又称漫水填充，像素法
// 本质是在寻找具有相同性质的联通块


#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> PII;
const int N = 110;
char a[N][N];
bool st[N][N];
int n, m;
int dx[] = { 0, 0, -1, 1, 1, 1, -1 , -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

void dfs(int i, int j)
{
	st[i][j] = true;

	for (int k = 0; k < 8; k++)
	{
		int x = i + dx[k], y = j + dy[k];
		if (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == 'W' && st[x][y] == false)
		{
			dfs(x, y);
		}
	} 

}

void bfs(int i, int j)
{
	queue<PII> q;
	q.push({ i, j });
	st[i][j] = true;

	while (q.size())
	{
		PII t = q.front(); q.pop();
		int i = t.first, j = t.second;
		for (int k = 0; k < 8; k++)
		{
			int x = i + dx[k], y = j+ dy[k];
			if (x >= 1 && x <= n && y >= 1 && y <= m && st[x][y] == false && a[x][y] == 'W')
			{
				q.push({ x, y });
				st[x][y] = true;
			}
		}
	}

}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n;i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			//cout << a[i][j] << " ";
		}
		//cout << endl;
	}

	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] == 'W' && st[i][j] == false)
			{
				ret++;
				//dfs(i, j);
				bfs(i, j);
			}

		}
	}
	cout << ret;
	return 0;
}