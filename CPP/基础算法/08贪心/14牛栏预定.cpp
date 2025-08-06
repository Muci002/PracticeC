// P2859

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
const int N = 5 * 1e4 + 10;
struct node
{
	int x;  // 起始时间 / 结束时间
	int y;  // 结束时间 / 牛棚标号
	int z;  // 编号

	bool operator< (const node& a) const
	{
		return x > a.x;
	}

}a[N];

priority_queue<node> heap;

bool cmp(const node& x, const node& y)
{
	return x.x < y.x;
}

int main()
{
	int n = 0; cin >> n;
	for (int i = 1; i <= n;i++)
	{
		cin >> a[i].x >> a[i].y;
		a[i].z = i;
	}

	sort(a + 1, a + n + 1, cmp);
	int ret[N] = { 0 };
	int num = 1;
	heap.push({ a[1].y, 1 });
	ret[a[1].z] = num;
	for (int i = 2; i <= n; i++)
	{
		int l = a[i].x, r = a[i].y;
		int time = heap.top().x;
		if (time < l)
		{
			int tmp = heap.top().y;
			ret[a[i].z] = tmp;
			heap.pop();
			heap.push({ r, tmp });
		}
		else
		{
			num++;
			ret[a[i].z] = num;
			heap.push({ r,num });
		}
		
		
	}
	
	cout << num << endl;
	
	for (int i = 1; i <= n; i++)
	{
		cout << ret[i] << endl;
	}

	return 0;
}
