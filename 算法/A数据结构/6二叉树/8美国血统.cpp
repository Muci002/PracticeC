// 洛谷P1827
#include <iostream>
#include <string>

using namespace std;

string a, b;

void dfs(int l1, int r1, int l2, int r2)
{
	// 递归出口

	if (l1 > r1) return;

	// 找到根节点
	
	int p = l1;
	while (a[p] != b[l2]) p++;

	// 划分左右区间
	dfs(l1, p - 1, l2 + 1, l2 +p -l1);
	dfs(p + 1, r1, l2 + p - l1 + 1, r2);

	cout << b[l2];
}

int main()
{
	cin >> a >> b;
	
	dfs(0, a.size() - 1, 0, b.size() - 1);
	return 0;
}