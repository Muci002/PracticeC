// P3740

// 在离散化的时候，会把有的区间缩小
// 此时在做“区间覆盖”问题的时候，
// 会把这个缩小的区间完全覆盖掉
// 解决方式：
// 在离散化[x, y] 的时候，
// 把 x + 1 和 y + 1 离散进去



#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 1010;

int n, m;
int a[N], b[N];

int pos;
int disc[N * 4];
int f[N * 4];
bool st[N * 4];
unordered_map<int, int> id;
unordered_set<int> mp;
int main()
{
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
		disc[++pos] = a[i];
		disc[++pos] = a[i] + 1;
		disc[++pos] = b[i];
		disc[++pos] = b[i] + 1;

	}
	sort(disc + 1, disc + pos + 1);
	//pos = unique(disc + 1, disc + pos + 1) - (disc + 1);
	int cnt = 0;
	for (int i = 1; i <= pos; i++)
	{
		int x = disc[i];
		if (id.count(x)) continue;
		cnt++;
		id[x] = cnt;
	}

	for (int i = 1; i <= n; i++)
	{
		int l = id[a[i]], r = id[b[i]];
		for (int j = l ; j <= r; j++)
		{
			f[j] = i;
		}
	}

	for (int i = 1; i <= cnt; i++)
	{
		if (f[i] == 0) continue;
		mp.insert(f[i]);
	}

	// 统计结果 - 数组中有多少个不同的数
	/*int ret = 0;
	for (int i = 1; i <= cnt; i++)
	{
		int x = f[i];
		if (!x || st[x]) continue;
		ret++;
		st[x] = true;
	}*/
	cout << mp.size();
	return 0;
}