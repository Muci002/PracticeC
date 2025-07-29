// P1873

#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;
const int N = 1e6 + 10;
LL a[N], n, m;

LL calu(int x)
{
	LL ret = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] <= x) continue;
		ret += (a[i] - x);
	}
	return ret;
}

int main()
{
	cin >> n >> m;
	LL maxlen = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxlen = max(maxlen, a[i]);
	}
	LL l = 0, r = maxlen;
	while (l < r)
	{
		LL mid = (l + r + 1) / 2;
		if (calu(mid) >= m) l = mid;
		else r = mid - 1;
	}

	cout << l;

	return 0;
}