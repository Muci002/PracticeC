// 所谓深度优先，就是说每次都尝试向更深的节点走，也就是一条路走到黑
// 当一条路走完，走到不能再走的时候，那就回去，继续去找别的路
// DFS 是利用树的递归定义，使用递归的形式进行遍历

// 用 vector 数组存储树 
// #include <iostream>
// #include <vector>

// using namespace std;

// const int N = 1e5 + 10;
// vector<int> edges[N]; // 存树
// bool st[N]; // 标记节点是否被遍历过

// void dfs(int u)
// {
// 	cout << u << " ";
// 	st[u] = true; // 标记节点已经被访问过了

// 	// 访问所有的孩子
// 	for (auto v: edges[u])
// 	{
// 		if (!st[v])
// 		{
// 			dfs(v);
// 		}
// 	}
// }

// int main()
// {
// 	// 建树
// 	int n; cin >> n;
// 	for (int i = 1; i < n; i++)
// 	{
// 		int a, b; cin >> a >> b;
// 		edges[a].push_back(b);
// 		edges[b].push_back(a);
// 	}

// 	dfs(1);

// 	return 0;
// }


// 用链式前向星建树
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int h[N], e[N * 2], ne[N * 2], id; // 存树
bool st[N]; // 标记节点是否被访问过

// 链式前向星存树
void add(int a, int b)
{
	e[++id] = b;
	ne[id] = h[a];
	h[a] = id;
}

void dfs(int u)
{
	cout << u << " ";
	st[u] = true;
	for (int i = h[u]; i; i = ne[i])
	{
		int v = e[i]; // 孩子
		if (!st[v])
		{
			dfs(v);
		}
	}
}

int main()
{
	int n; cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b; cin >> a >> b;
		add(a, b); add(b, a);
	}

	dfs(1);
	return 0;
}