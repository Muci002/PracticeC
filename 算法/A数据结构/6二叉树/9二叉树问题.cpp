// 洛谷P3884
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int N = 110;

vector<int> edges[N];
int fa[N]; // 存父亲节点
int dist[N]; // 存节点到 x 的距离
// 深度 = max( 左子树的深度， 右子树的深度）
int dfs1(int u)
{
	int ret = 0; 
	for (auto v : edges[u])
	{
		ret = max(ret, dfs1(v));
	}
	return ret + 1;
}

// 最大的度
int bfs()
{
	// 队列辅助 bfs
	queue<int> q; 

	// 根节点入队
	q.push(1);
	
	int ret = 0; // 记录最大宽度

	while (q.size()) // 当队列不为空
	{
		
		int sz = q.size();
		ret = max(ret, sz);
		while (sz--)  // 同一层全部出队， 下一层入队
		{
			int u = q.front(); q.pop();
			for (auto e: edges[u])
			{
				q.push(e);
			}
		}
	}

	return ret;

}

// 距离
//void distance(int x, int y)
//{
//	int cntx = 0; // 计算到根节点的距离
//	for (int i = fa[x]; i; i = fa[i])
//	{
//		st[i] = true;
//		cntx++;
//	}
//	// cout << cntx << endl;
//
//	int cnty = 0;
//
//	for (int i = fa[y]; i; i = fa[i])
//	{
//		cnty++;
//		if (st[i])
//		{
//			int sum = 0; 
//			for(int j = fa[i]; j; j = )
//		}
//	}
//}

int main()
{
	int n; cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		edges[u].push_back(v);

		// 存父亲节点
		fa[v] = u;

	}
	
	// 深度
	cout << dfs1(1) << endl;

	// 宽度
	cout << bfs() << endl;

	// 距离
	int x, y; cin >> x >> y;
	
	while (x != 1)
	{
		dist[fa[x]] = dist[x] + 1;
		x = fa[x];
	}

	int len = 0;
	while (y != 1 && dist[y] == 0)
	{
		len++;
		y = fa[y];
	}

	cout << dist[y] * 2 + len << endl;

	return 0;
}