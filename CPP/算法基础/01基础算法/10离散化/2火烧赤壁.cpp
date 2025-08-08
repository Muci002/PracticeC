// P1496

// 离散化 + 差分
// 1.整个着火信息全部离散化
// 2.在离散化的基础上，使用差分
// 3.在离散化之前的基础上，求真实区间长度


#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
const int N = 2e4 + 10;

int n;
int a[N], b[N];

int pos;
int disc[N * 2];

unordered_map<int, int> id;

int f[N * 2];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
		disc[++pos] = a[i];
		disc[++pos] = b[i];
	}

	sort(disc + 1, disc + 1 + pos);
	pos = unique(disc + 1, disc + 1 + pos) - (disc + 1);
	for (int i = 1; i <= pos; i++)
	{
		id[disc[i]] = i;
	}

	// 利用离散化做差分
	for (int i = 1; i <= n; i++)
	{
		int l = id[a[i]], r = id[b[i]];
		f[l]++, f[r]--;
	}

	// 利用前缀和还原数组
	for (int i = 1; i <= pos; i++)
	{
		f[i] = f[i] + f[i - 1];

	}

	// 统计结果
	int ret = 0;
	for (int i = 1; i <= pos; i++)
	{
		int j = i;
		while (j <= pos && f[j] > 0) j++;
		ret += disc[j] - disc[i];
		i = j;
	}
	cout << ret;
	return 0;
}