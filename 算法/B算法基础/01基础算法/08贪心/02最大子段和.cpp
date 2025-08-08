// P1115


#include <iostream>
#include <cmath>
using namespace std;
const int N = 2 * 1e5 + 10;
int a[N], n;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int sum = 0;
	int ret = -0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
	{
		sum += a[i];
		ret = max(ret, sum);
		if (sum < 0) sum = 0;
	}
	cout << ret;
	return 0;
}


//反证法，没看懂