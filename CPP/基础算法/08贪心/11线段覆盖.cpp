// P1803

// 1.先按照左端升序排列
// 当区间重叠的时候，尽可能的保留右端点较小的区间
// 当区间不重叠的时候，以下一个区间为基准，继续判断


#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e6 + 10;

struct node
{
	int l; 
	int r;
}a[N];

bool cmp(const node& x, const node& y)
{
	return x.l < y.l;
}

int main()
{
	int n = 0; cin >> n;
	for (int i = 1; i <= n;i++) cin >> a[i].l >> a[i].r;

	sort(a + 1, a + n + 1, cmp);

	int ret = 1;
	int r = a[1].r;  // 以第一个区间右端点为基准比较
	for (int i = 2; i <= n; i++)
	{
		int left = a[i].l, right = a[i].r;
		if (left < r)   // 有重叠
		{
			// 尽可能保留右端点较小的区间
			r = min(r, right);
		}
		else  // 不重叠
		{
			// 以下一个区间为基准，继续判断
			ret++;
			r = right;
		}
	}
	cout << ret;
	return 0;
}