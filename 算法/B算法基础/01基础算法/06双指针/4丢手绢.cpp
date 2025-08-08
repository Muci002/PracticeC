// https://ac.nowcoder.com/acm/problem/207040


#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;
typedef long long LL;
LL a[N];
LL sum;

int main()
{
	int n = 0; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}

	// 当第一次出现 2*K >= sum 的时候就是最的点
	// 1.初始化
	int left = 1, right = 1;
	LL k = 0;
	LL ret = 0;
	while (right <= n && left <= n)
	{
		// 2.进窗口
		k += a[right];

		// 3.出窗口
		while (k * 2 >= sum)
		{
			// 更新结果
			ret = max(ret, sum-k);
			k -= a[left++];
		}
		ret = max(ret, k);
		right++;
	}
	cout << ret;

	return 0;
}