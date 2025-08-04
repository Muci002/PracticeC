// P1056

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
const int N = 1010;

struct node
{
	int index;
	int cnt;
}row[N], col[N];

bool cmp1(node& x, node& y)
{
	return x.cnt > y.cnt;
}

bool cmp2(node& x, node& y)
{
	return x.index < y.index;
}

int main()
{
	int m = 0, n = 0, k = 0, l = 0, d = 0;
	cin >> m >> n >> k >> l >> d;
	// 初始化结构体数组
	for (int i = 1; i <= m; i++) row[i].index = i;
	for (int i = 1; i <= n; i++) col[i].index = i;

	while (d--)
	{
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2) col[min(y1, y2)].cnt++;
		if (y1 == y2) row[min(x1, x2)].cnt++;
	}

	// 对两个数按cnt排序
	sort(row + 1, row + m + 1, cmp1);
	sort(col + 1, col + n + 1, cmp1);

	// 对两个数按index排序
	sort(row + 1, row + k + 1, cmp2);
	sort(col + 1, col + l + 1, cmp2);

	for (int i = 1; i <= k; i++) cout << row[i].index << " ";
	cout << endl;
	for (int i = 1; i <= l; i++) cout << col[i].index << " ";

	return 0;
}