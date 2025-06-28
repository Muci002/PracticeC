// 链式存储
// 竞赛中给定的树结构一般都是有编号的。
// 我们可以创建两个数组 l[N] 和 r[N]
// l[i] 表示节点号为 i 的节点的左孩子的编号
// r[i] 表示节点号为 i 的节点的右孩子的编号

#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int l[N], r[N];

int main()
{
	int n = 0; cin >> n;
	// 存二叉树
	for (int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
	}
	return 0;
}