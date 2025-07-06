// set 是红黑树实现的，unordered_set 是哈希表实现的
// set 是有序的，unordered_set 是无序的
// 使用是完全一样的
// 没有 lower_bound 和 upper_bound, 因为是无序的
// 头文件 <unordered_set>



// 用 unordered_map 存图
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, vector<int>> edges;

int main()
{
	int n = 0; cin >> n;
	while(n--)
	{
		int a, b; cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	return 0;
}