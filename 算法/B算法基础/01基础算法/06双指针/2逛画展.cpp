// P1638

#include <iostream>
#include <unordered_map>
using namespace std;
const int N = 1e6 + 10;
int a[N], n, m;
unordered_map<int, int> mp;  // 窗口中每副画出现的次数

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];

	// 1.初始化
	int left = 1, right = 1;
	int len = 0x3f3f3f3f;
	int cnt = 0;
	int x = 0, y = 0;
	while (right <= n && left <= n)
	{
		// 2.进窗口:让right所指的元素进入窗口
		mp[a[right]]++;
		if (mp[a[right]] == 1) cnt++;
		
		// 判断窗口是否合法
		while (cnt >= m)
		{
			// 更新结果
			int cmp = right - left + 1;
			if (cmp < len)
			{
				len = cmp;
				x = left, y = right;
			}
			// 出窗口
			mp[a[left]]--;
			if (mp[a[left]] == 0) cnt--;
			left++;
		}

		right++;
	}
	cout << x << " " << y;
	return 0;
}