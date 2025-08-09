// P1115

// 最终结果的位置：
// 1. 要么在左边 → dfs
// 2. 要么在右边 → dfs
// 3. 横跨中间位置，一左一右 

#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
LL n, a[N];
LL f[N];

LL merge(int left, int right)
{
	LL ret1 = 0, ret2 = 0, ret3 = 0;
	if (left >= right) return a[left];

	LL mid = (left + right) >> 1;
	ret1 = merge(left, mid);
	ret2 = merge(mid + 1, right);

	// 横跨中间位置
	LL maxl = -0x3f3f3f3f, maxr = -0x3f3f3f3f;
	for (int i = left; i <= mid; i++)  // 左边最大
	{
		maxl = max(maxl, f[mid] - f[i - 1]);
	}

	for (int i = right; i >= mid + 1; i--) // 右边最大
	{
		maxr = max(maxr, f[i] - f[mid]);
	}
	ret3 = maxl + maxr;
	return max(ret1, max(ret2, ret3));
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[i] = f[i - 1] + a[i];
	}

	cout << merge(1, n);

	return 0;
}