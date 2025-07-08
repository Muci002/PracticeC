// P3405
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	unordered_map<string, int> mp;  // < 拼接后的关系, 出现的次数 >
	int n = 0; cin >> n;
	int ret = 0;
	while (n--)
	{
		string a, b; cin >> a >> b;
		a = a.substr(0, 2);  
		if (a == b) continue; // 跳过同一个洲
		ret += mp[b + a];
		mp[a + b]++;
	}
	cout << ret;
	return 0;
}