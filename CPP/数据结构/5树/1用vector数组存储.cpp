// edges[i] 里面存储着 i 号节点的所有孩子
// 对于 i 的孩子，直接 edges[i].push_back() 进去
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
vector<int> edges[N]; // 存储树

int main()
{
	int n; cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b; cin >> a >> b;
		// 和b之间有一条边
		edges[a].push_back(b);
		edges[b].push_back(a);
	}


	return 0;
}