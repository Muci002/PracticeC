//P1878 舞蹈课
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

const int N = 2 * 1e5 + 10;
int sex[N];  // 0 表示女，1 表示男

// 双向链表存舞蹈实力，快速删除
int e[N], pre[N], ne[N];

// 标记是否出列
bool st[N];

struct node
{
	int d; // 实力差
	int l; // 左编号
	int r; // 右编号

	bool operator < (const node& x) const
	{
		// 小根堆，大数据下沉
		if (d != x.d) return d > x.d;
		else if (l != x.l) return l > x.l;
		else return r > x.r;
	}

};

vector<node> arr; // 存出场队伍

priority_queue<node> heap;

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		char ch; cin >> ch;
		if (ch == 'B') sex[i] = 1;
	}

	// 将实力存入链表
	for (int i = 1; i <= n; i++)
	{
		cin >> e[i];
		pre[i] = i - 1;
		ne[i] = i + 1;
	}
	ne[n] = 0;

    // 把所有的异性差放入堆中
	for (int i = 2; i <= n; i++)
	{
		if (sex[i] != sex[i - 1]) 
		{
			int t = abs(e[i] - e[i - 1]);
			heap.push({ t, i - 1, i });
		}
	}

	while (heap.size())
	{
		node t = heap.top(); heap.pop();
		if (st[t.l] || st[t.r]) continue;
		arr.push_back(t);
		st[t.l] = st[t.r] = true;

		// 修改指针，还原新的队列
		ne[pre[t.l]] = ne[t.r];
		pre[ne[t.r]] = pre[t.l];

        // 判断新的左右是否会成为一对
		if (pre[t.l] && ne[t.r] && sex[pre[t.l]] != sex[ne[t.r]])
		{
			heap.push({ abs(e[pre[t.l]] - e[ne[t.r]]), pre[t.l], ne[t.r] });
		}

	}

	cout << arr.size() << endl;
	for (auto e : arr)
	{
		cout << e.l << " " << e.r << endl;
	}

	return 0;
}