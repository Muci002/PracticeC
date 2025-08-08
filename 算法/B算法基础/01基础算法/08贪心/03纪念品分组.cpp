// P1094

#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int N = 3 * 1e4 + 10;
int a[N], n, w;
unordered_map<int, int> mp;

int main()
{
	cin >> w >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i];
		mp[a[i]]++;
	}
	sort(a + 1, a + 1 + n);
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if(mp[a[i]])
		{
			int tmp = w - a[i];
			mp[a[i]]--;
			auto t = upper_bound(a + 1, a + 1 + n, tmp);
			while ((--t) != (a))
			{
				if (*t <= tmp && mp.count(*t) && mp[*t])
				{
					mp[*t]--;
					break;
				}
			}
			
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}



//······························································
//······························································

#include <iostream>
#include <algorithm>

using namespace std;
const int N = 3 * 1e4 + 10;
int a[N], n, w;

int main()
{
	cin >> w >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 1, r = n; 
	int cnt = 0;
	while (l <= r)
	{
		if (a[l] + a[r] <= w) l++; 
		r--;
		cnt++;
	}
	cout << cnt;
	return 0;
}


// 交换论证法
// 在最优解不失去它“最优性”的前提下，
// 能够逐步调整成贪心解