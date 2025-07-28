// 洛谷 P1102

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long LL;
const int N = 200010;

LL a[N];

int main()
{
	LL n = 0, c = 0;
	cin >> n >> c;
    if(!n)
    {
        cout << 0;
        return 0;
    }
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	LL ret = 0;
	for (int i = 2; i <= n; i++)
	{
		LL b = a[i] - c;
		ret += upper_bound(a + 1, a + i, b) - lower_bound(a + 1, a + i, b);
	}
    cout << ret;

	return 0;
}