// P1228


#include <iostream>
#include <cstdio>
using namespace std;

int k, x, y;

// 左上角坐标，区间长度，障碍物位置
void dfs(int a, int b, int len, int x, int y)
{
	if (len == 1) return;
	len /= 2;
	
	// 障碍物在左上角
	if (x < a + len && y < b + len)
	{
		printf("%d %d %d\n", a + len, b + len, 1);
		dfs(a, b, len, x, y);
		dfs(a, b + len, len, a + len - 1, b + len);
		dfs(a + len, b, len, a + len, b + len - 1);
		dfs(a + len, b + len, len, a + len, b + len);
	}
	// 障碍物在右上角
	if (x < a + len && y >= b + len)
	{
		printf("%d %d %d\n", a + len , b + len - 1, 2);
		dfs(a, b, len, a + len - 1, b + len - 1);
		dfs(a, b + len, len, x, y);
		dfs(a + len, b, len, a + len, b + len - 1);
		dfs(a + len, b + len, len, a + len, b + len);
	}
	// 障碍物在左下角
	if (x >= a + len && y < b + len)
	{
		printf("%d %d %d\n",a + len - 1, b + len , 3);
		dfs(a, b, len, a + len - 1, b + len-1);
		dfs(a, b + len, len, a + len - 1, b + len);
		dfs(a + len, b, len, x, y);
		dfs(a + len, b + len, len, a + len, b + len);
	}
	// 障碍物在右下角
	if (x >= a + len && y >= b + len)
	{
		printf("%d %d %d\n", a + len - 1, b + len-1, 4);
		dfs(a, b, len, a + len - 1, b + len - 1);
		dfs(a, b + len, len, a + len - 1, b + len);
		dfs(a + len, b, len, a + len, b + len - 1);
		dfs(a + len, b + len, len, x, y);
	}

}

int main()
{
	cin >> k >> x >> y;
	k = (1 << k); // 2 的 k 次方

	// 左上角坐标，区间长度，障碍物位置
	dfs(1, 1, k, x, y);

	return 0;
}