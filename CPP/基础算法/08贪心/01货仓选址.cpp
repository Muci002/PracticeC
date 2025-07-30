//P10452

// 货仓选址问题的最优解不是由最大值和最小值的中间点决定的，
// 而是由所有点的中位数决定的。

#include <iostream>
#include <cmath>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int a[N];

int main()
{
	int n = 0; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ret = 0;
	sort(a + 1, a + n + 1);
	
    // 用中间位置求
	// for (int i = 1; i <= n; i++)
	// {
	// 	ret += abs(a[i] - a[(n + 1) / 2]);
	// }

    // 用绝对值不等式结论求
    for (int i = 1 ; i <= n / 2; i++)
    {
        ret += abs(a[i] - a[n+1-i]);
    }

	cout << ret;

	return 0;
}



// 绝对值不等式：
// |a - x| + |b - x| >= |a - b|
// 当这个 x 位于 a 和 b 的中间位置时
// 左式取得最小值
