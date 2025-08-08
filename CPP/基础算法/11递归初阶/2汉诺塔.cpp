// 信息奥赛1205
// https://ybt.ssoier.cn/problem_show.php?pid=1205

// 相同的问题
// x 柱子上有 n 个盘子，需要借助 y 的帮助，转移到 z 上


#include <iostream>
#include <cstdio>
using namespace std;

// x 上的 n 个盘子借助 y 的帮助转移到 z 上
void dfs(int n, char x, char y, char z)
{
	if (n == 0) return;
	dfs(n - 1, x, z, y);
	//cout << x << "->" << n << "->" << z << endl;
	printf("%c->%d->%c\n", x, n, z);
	dfs(n - 1, y, x, z);
}

int main()
{
	int n = 0; cin >> n;
	char x, y, z; cin >> x >> y >> z;

	dfs(n, x, z, y);

	return 0;
}