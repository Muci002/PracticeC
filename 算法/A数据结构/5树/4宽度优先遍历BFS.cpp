// 所谓宽度优先，就是每次都尝试访问同一层的节点。如果一层都访问完了，再访问下一层
// 借助队列
// 1. 创建一个队列，辅助 BFS
// 2. 根节点入队
// 3. 如果队列不为空，队头节点出队并访问该节点，然后将该节点的孩子依次入队
// 4. 重复 3 过程，直到队列为空
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int N = 1e5 + 10;

// 用 vector 存树
vector<int> edges[N];
bool st[N];

// 宽度优先遍历 BFS
void bfs()
{
	queue<int> q; // 辅助 BFS
	q.push(1); // 根节点入队
	st[1] = true;
	while (q.size())  // 队列不为空，队头元素出队并访问，孩子入队
	{
		int u = q.front();
		cout << u << " ";
		q.pop();

		for (auto v : edges[u])
		{
			if (!st[v])
			{
				q.push(v);
				st[v] = true;
			}
		}

	}
}

int main()
{
	int n = 0; cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b; cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	bfs();

	return 0;
}

#include <iostream>
#include <queue>

using namespace std;

const int N = 1e5 + 10;
int h[N], e[N*2], ne[N*2], id;  // 链式前向星存储
bool st[N];

void add(int a, int b)
{
	e[++id] = b;
	ne[id] = h[a];
	h[a] = id;
}

// 宽度优先遍历
void bfs()
{
	// 创建一个队列辅助bfs
	queue<int> q;
	// 根节点入队
	q.push(1);
	st[1] = true;
	// 若队列不为空，队头节点出队并访问该节点，然后将该点的孩子依次入队
	while (q.size())
	{
		int u = q.front();
		q.pop();
		cout << u << " ";
		for (int i = h[u]; i; i = ne[i])
		{
			int v = e[i];
			if (!st[v])
			{
				q.push(v);
				st[v] = true;
			}
		}
	}
}

int main()
{
	int n = 0; cin >> n;
	for (int i = 1; i < n;i++)
	{
		int a, b; cin >> a >> b;
		add(a, b); add(b, a);
	}

	bfs();

	return 0;
}