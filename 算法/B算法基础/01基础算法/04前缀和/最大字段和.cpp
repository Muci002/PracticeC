//P1115

#include <iostream>
#include <cmath>

using namespace std;
const int N = 2 * 1e5 + 10;
typedef long long LL;
LL f[N];
LL n;

int main()
{
	cin >> n;
	LL minvalu = 0x3f3f3f3f;
	LL ret = -0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
	{
		LL x; cin >> x;
		f[i] = f[i - 1] + x;
		minvalu = min(minvalu, f[i-1]);
		ret = max(ret, f[i] - minvalu);
	}
	cout << ret << endl;
	return  0;
}