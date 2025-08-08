//https://ac.nowcoder.com/acm/problem/213140
// 每次挑选出当前数组中最大的偶数，然后减小一半
// 利用大根堆来实现这个算法
#include <iostream>
#include <queue>

using namespace std;

typedef long long LL;
priority_queue<int> heap;

LL sum;

int main()
{
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int x = 0; cin >> x;
		sum += x;
		if (x % 2 == 0)
		{
			heap.push(x);
		}
	}

	while (heap.size() && k--)
	{
		int t = heap.top() / 2;
		sum -= t;
		heap.pop();
		if (t % 2 == 0)
		{
			heap.push(t);
		}
	}

	cout << sum << endl;

	return 0;
}