// P2887
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 2510;

struct node
{
	int x, y;
}a[N], b[N];

bool cmp(const node& a, const node& b)
{
	return a.x > b.x;
}

int main()
{
	int n = 0, m = 0; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
	for (int i = 1; i <= m; i++) cin >> b[i].x >> b[i].y;

	sort(a + 1, a + n + 1, cmp);
	sort(b + 1, b + m + 1, cmp);

	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		int l = a[i].x, r = a[i].y;

		// 按照从大到小的顺序分配
		int flag = false;
		for (int j = 1; j <= m; j++)
		{
			int w = b[j].x, &cnt = b[j].y;
			if (w < l) break;
			if (w > r || cnt == 0) continue;
			cnt--;
			ret++;
			break;
		}
	}
	cout << ret;
	return 0;
}