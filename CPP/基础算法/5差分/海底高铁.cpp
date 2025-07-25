// P3406
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
LL f[N];


int main()
{
	int n = 0, m = 0; cin >> n >> m;
	int sta = 0; cin >> sta; // 初始位置
	for (int i = 1; i < m; i++)
	{
		int next = 0; cin >> next;
		int l = min(sta, next); 
		int r = max(sta, next);
		sta = next;
		f[l]++, f[r]--;
	}

	// 前缀和还原数组
	for (int i = 1; i <= n; i++) f[i] = f[i] + f[i - 1];

	LL ret = 0;
	for (int i = 1; i < n; i++)
	{
		int a = 0, b = 0, c = 0; cin >> a >> b >> c;
		ret += min(f[i] * a, f[i] * b + c);
	}
	cout << ret;
	return 0;
}