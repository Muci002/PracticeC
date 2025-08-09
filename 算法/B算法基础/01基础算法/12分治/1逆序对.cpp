// P1908

// 分治，字面上的解释是「分而治之」，
// 就是把一个复杂的问题分成两个或更多的相同的子问题，
// 直到最后子问题可以简单的直接求解，
// 原问题的解即子问题的解的合并。

#include <iostream>

using namespace std;
typedef long long LL;
const int N = 5e5 + 10;
int n, a[N];
int tmp[N];   // 辅助归并排序

LL merge(int left, int right)
{
	
	if (left >= right) return 0;
	LL ret = 0;
	int mid = (left + right) >> 1;
	ret += merge(left, mid);
	ret += merge(mid + 1, right);

	// 合并两个有序数组   一左一右情况
	int cur1 = left, cur2 = mid + 1, i = left;
	while (cur1 <= mid && cur2 <= right)
	{
		if (a[cur1] <= a[cur2])	tmp[i++] = a[cur1++];
		else
		{
			tmp[i++] = a[cur2++];
			ret += mid - cur1 + 1;
		}
	}

	while (cur1 <= mid)	tmp[i++] = a[cur1++];
	while (cur2 <= right) tmp[i++] = a[cur2++];
	for (int j = left; j <= right; j++) a[j] = tmp[j];
	return ret;
}

int main()
{
	cin >> n; 
	for (int i = 1; i <= n; i++) cin >> a[i];

	cout << merge(1, n) << endl;
}