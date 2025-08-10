// P1036

#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;
const int N = 22;
int n, k;
int a[N];
int sum;
unordered_set<int> st;

bool check(int x)
{
	// 小于2的不是质数
	if (x < 2) return false;
	// 2是质数
	if (x == 2) return true;
	// 偶数不是质数（除了2）
	if (x % 2 == 0) return false;
	// 只需要检查到平方根，且可以只检查奇数
	for (int i = 2; i <= sqrt(x); i++)
	{
		if ((x % i) == 0) return false;
	}
	return true;
}

int dfs(int pos, int begain)
{
	int ret = 0;
	if (pos > k)
	{
		// 判断质素
		if (check(sum)) ret++;
		return ret;
	}
	for (int i = begain; i <= n; i++)
	{
		if (st.count(i)) continue;
		sum += a[i];
		st.insert(i);
		ret += dfs(pos+ 1, i + 1);
		// 恢复现场
		sum -= a[i];
		st.erase(i);
	}
	return ret;
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n;i++) cin >> a[i];
	cout << dfs(1, 1);
	return 0;
}