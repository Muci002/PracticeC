//P2280

#include <iostream>
#include <algorithm>

using namespace std;
const int N = 5 * 1e3 + 10;
int a[N][N], f[N][N];
int x, y, t, m;


int main()
{
	cin >> t >> m;
	while (t--)
	{
		int v = 0;
		cin >> x >> y >> v;
		x++, y++;   // 防止边界情况
		a[x][y] += v;
	}
	
	int n = 5001;
	// 预处理二维前缀和
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
		}
	}


	// 以右下角枚举所有的正方形区间
	m = min(n, m); // 防止 m 过大的情况
	int ret = 0;
	for (int i = m; i <= n; i++)
	{
		for (int j = m; j <= n; j++)
		{
			ret = max(ret, f[i][j] - f[i][j - m] - f[i - m][j] + f[i - m][j - m]);
		}
	}

	cout << ret << endl;

	return 0;
}