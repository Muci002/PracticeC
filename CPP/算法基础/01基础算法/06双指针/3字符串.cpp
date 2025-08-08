// https://ac.nowcoder.com/acm/problem/18386

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;
string s;
unordered_map<char, int> mp;

int main()
{
	cin >> s;
	int len = s.size();

	// 1.初始化
	int left = 0, right = 0;
	int cnt = 0;
	int ret = 0x3f3f3f3f;
	while (right < len && left < len)
	{
		// 2.进窗口
		mp[s[right]]++;
		if (mp[s[right]] == 1) cnt++;

		// 3.判断
		while (cnt >= 26)
		{
			// 4.更新结果
			ret = min(ret, right - left + 1);
			mp[s[left]]--;
			if (mp[s[left]] == 0) cnt--;
			left++;
		}

		right++;

	}

	cout << ret;

	return 0;
}