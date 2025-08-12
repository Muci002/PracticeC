// P10483


#include <iostream>
#include <algorithm>

using namespace std;
const int N = 20;

int c[N]; // 小猫的信息
int n, w;
int s[N]; // 每一辆车目前的总重
int cnt;  // 当前用了多少车

int ret = N;  //最优性剪枝

bool cmp(int x, int y)
{
	return x > y;
}

void dfs(int pos)
{
	// 策略二：最优性剪枝
	if (cnt >= ret) return;
	
	if (pos > n)
	{
		ret = cnt;
		return;
	}

	// 策略三：优化搜索顺序
	// 先安排在已有的车辆上
	for (int i = 1; i <= cnt; i++)
	{
		// 策略一：可行性剪枝
		if (s[i] + c[pos] > w) continue;
		s[i] += c[pos];
		dfs(pos + 1);
		// 恢复现场
		s[i] -= c[pos];
	}

	// 重开一辆车
	cnt++;
	s[cnt] = c[pos];
	dfs(pos + 1);
	s[cnt] = 0;
	cnt--;

}

int main()
{
	cin >> n >> w;
	for (int i = 1; i <= n; i++) cin >> c[i];

	// 策略三：优化搜索顺序
	sort(c + 1, c + n + 1, cmp);

	dfs(1);
	cout << ret;
	return 0;
}