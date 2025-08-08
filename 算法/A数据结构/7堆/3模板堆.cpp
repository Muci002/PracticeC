//P3378 【模板】堆
#include <iostream>
#include <utility>
using namespace std;
typedef unsigned long long ULL;
const int N = 1e6 + 10;

ULL heap[N], n;

// 向上调整， 小根堆
void up(int child)
{
	int parent = child / 2;

	// 当父节点存在，并且父节点大于孩子节点的时候
	while (parent >= 1 && heap[parent] > heap[child])
	{
		swap(heap[parent], heap[child]);
		child = parent;
		parent = child / 2;
	}

}

// 向下调整
void down(int parent)
{
	int child = parent * 2;

	while (child <= n)
	{
		// 找出最小的孩子
		if (child + 1 <= n && heap[child] > heap[child + 1]) child++;
		if (heap[child] >= heap[parent]) return;
		swap(heap[parent], heap[child]);
		parent = child;
		child = parent * 2;
	}

}

int main()
{
	ULL t = 0, op = 0, x = 0;
	cin >> t;
	while (t--)
	{
		cin >> op; 
		if (op == 1)
		{
			cin >> x;
			heap[++n] = x;
			up(n);
		}
		else if (op == 2)
		{
			if (n == 0) continue;
			cout << heap[1] << endl;
		}
		else if(op == 3)
		{
			if (n == 0) continue;
			swap(heap[1], heap[n]);
			n--;
			down(1);
		}
	}

	return 0;
}