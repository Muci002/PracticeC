// P4913
// 二叉树的高度 = max( 左子树的高度， 右子树的高度 ) + 1;
// 相同子问题，用 递归 解决
// 递归函数的设计
// 1. 函数头
// 2. 函数体
// 3. 递归出口

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;
int l[N], r[N];

int dfs(int root)
{
	if (!root) return 0;
	return max(dfs(l[root]), dfs(r[root])) + 1;
}

int main()
{
	int n = 0; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
	}

	cout << dfs(1);

	return 0;
}