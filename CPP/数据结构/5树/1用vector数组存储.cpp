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