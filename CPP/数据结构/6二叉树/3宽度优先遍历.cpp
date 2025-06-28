#include <iostream>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

int l[N], r[N];

void bfs()
{
	queue<int> q;  // 队列辅助 BFS
	q.push(1);  // 根节点入队

	while (q.size()) // 队列不为空，头节点出队并访问该节点，将该节点的孩子依次入队
	{
		int u = q.front();
		cout << u << " ";
		q.pop();
		if (l[u]) q.push(l[u]);
		if (r[u]) q.push(r[u]);
	}
	
}

int main()
{
	int n = 0; cin >> n; 
	for (int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
	}

	bfs();

	return 0;
}