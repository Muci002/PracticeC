[P1596]
1. 用bfs，dfs搜索联通块
2. 利用并采集来维护水坑信息，把相邻的‘W’放在同一个集合中

1. 如何把相邻的‘W’合并在同一个集合中？
>八数码难题中有学过，在搜索BFS的04题[P1379]
>

```cpp
#include <iostream>

using namespace std;

const int N = 110;
int fa[N*N];
char a[N][N];
int dx[4] = { -1, -1, -1, 0 };
int dy[4] = { -1,  0,  1, -1 };

int find(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}



int main()
{

	int n = 0, m = 0; cin >> n >> m;
	for (int i = 0; i < n * m; i++) fa[i] = i;
	int cnt = 0;
	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			
			if (a[i][j] == 'W')
			{
				// 查找有没有相连
				for (int k = 0; k < 4; k++)
				{
					int x = i + dx[k];
					int y = j + dy[k];
					if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] == '.') continue;
					// 二维转一维
					int pos1 = i * m + j;
					int pos2 = x * m + y;
					//合并
					//合并的是元素所在的集合，不是这两个元素！
					int p = find(pos2);
					int p2 = find(pos1);
					fa[p] = p2;
				}
			}
			else cnt++;
		}
	}

	int ret = 0;
	for (int i = 0; i < n * m; i++)
	{
		if (fa[i] == i) ret++;
	}
	cout << ret - cnt;
	return 0;
}
```






[P1596]:https://www.luogu.com.cn/problem/P1596
[P1379]:https://www.luogu.com.cn/problem/P1379