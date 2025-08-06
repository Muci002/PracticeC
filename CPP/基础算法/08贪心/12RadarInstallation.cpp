// UVA1193

// 先根据左端点排序，互相重叠的区间是连续的
// 当两个区间重叠时，应该用右端点较小的区间，继续向后找
// 不重叠时，以下一个区间为基准，继续向后找


#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 1010;

struct node
{
	double l, r;
}a[N];

bool cmp(const node& x, const node& y)
{
	return x.l < y.l;
}

int main()
{
	int n = 0, R = 0; 
	int cnt = 0;
	while(cin >> n >> R)
	{
		if (!n && !R) break;
		cnt++;
		bool flag = false;
		for (int i = 1; i <= n;i++)
		{
			// 将二维转换为一维
			double x = 0, y = 0; cin >> x >> y;
			if (y > R)
			{
				cout << "Case " << cnt << ": " << -1 << endl;
				flag = true;
				break;
			}
			double len = sqrt(R * R - y * y);
			a[i].l = x - len;
			a[i].r = x + len;
		}
		if (flag) continue;
		// 根据左端点排序，互相重叠的区间是连续的
		sort(a + 1, a + n + 1, cmp);

		int ret = 1;
		double r = a[1].r;
		for (int i = 2; i <= n; i++)
		{
			double left = a[i].l, right = a[i].r;
			if (left <= r)
			{
				// 有重叠，用右端点较小的区间，继续向后找
				r = min(right, r);
			}
			else
			{
				ret++;
				r = right;
			}
		}

		cout << "Case " << cnt << ": " << ret << endl;

	}

	return 0;
}