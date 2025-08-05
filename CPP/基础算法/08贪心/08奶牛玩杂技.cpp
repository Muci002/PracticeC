// P2878
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 5 * 1e4 + 10;
struct node
{
	int w;
	int s;
}a[N];

bool cmp(const node& x, const node& y)
{
	return max(-x.s,x.w - y.s) < max(y.w - x.s, -y.s);
}

int main()
{
	int n = 0; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].w >> a[i].s;

	sort(a + 1, a + 1 + n, cmp);

	int ret = -0x3f3f3f3f;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		ret = max(ret, sum - a[i].s);
		sum += a[i].w;
	}

	cout << ret;

	return 0;
}