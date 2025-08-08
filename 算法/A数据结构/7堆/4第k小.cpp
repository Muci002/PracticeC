//https://ac.nowcoder.com/acm/problem/214362
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	priority_queue<int> heap;
	int n, m, k; cin >> n >> m >> k;
	while (n--)
	{
		int x = 0; cin >> x;
		heap.push(x);
	}

	while (m--)
	{
		while (heap.size() > k)
		{
			heap.pop();
		}
		int op = 0; cin >> op;
		if (op == 1)
		{
			int x = 0; cin >> x;
			heap.push(x);
		}
		else if (op == 2)
		{
			if (heap.size() != k)
			{
				cout << -1 << endl;
				continue;
			}
			cout << heap.top() << endl;
		}
	}

	return 0;
}