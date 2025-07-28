// P1678


#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
LL a[N];
int n, m;

int main()
{
    // 不加左右护法需要判断边界情况
    // 左右护法不能影响原来的值
	cin >> n >> m;
	a[0] = -1e7;  // 左右护法
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	LL ret = 0;
	for (int i = 1; i <= m;i++) 
	{
		LL x = 0; cin >> x;
		auto it = lower_bound(a + 1, a + n + 1, x);
		auto tmp = it - 1;
		ret += min(abs(x - *it), abs(x - *tmp));
	}

	cout << ret;

	return 0;
}