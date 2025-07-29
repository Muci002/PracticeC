// P2678

#include <iostream>

using namespace std;
const int N = 5 * 1e5 + 10;
typedef long long LL;
LL a[N],L, n, m;

int calu(int x)
{
	LL ret = 0;
	// 用两个指针模拟跳跃
	int i = 0, j = i + 1;
	while (j <= n  && i <= n + 1)
	{
		if (a[j] - a[i] >= x)
		{
			i = j;
			j = i + 1;

		}
		else
		{
			j++;
			ret++;
		}

	}
	return ret;
}

int main()
{
	cin >> L >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[n + 1] = L;

	int l = 1, r = L;
	while (l < r)
	{
		LL mid = (l + r + 1) / 2;
		if (calu(mid) <= m) l = mid;
		else r = mid - 1;
	}
	cout << r;

	return 0;
}