#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int heap[N], n;

// 向上调整算法
void up(int child)
{
	int parent = child / 2;
	
	// 当父节点存在，并且孩子节点大于父节点的权值时
	while (parent >= 1 && heap[child] > heap[parent])
	{
		swap(heap[parent], heap[child]);
		child = parent;
		parent = child / 2;
	}

}

// 向下调整算法
void down(int parent)
{
	int child = parent * 2;
	
	// 如果存在孩子节点
	while (child <= n)  // 堆是一个完全二叉树，所以如果左孩子不存在，那么右孩子一定不存在
	{
		// 找出最大的孩子
		if (child + 1 <= n && heap[child + 1] > heap[child]) child++;
		if (heap[parent] >= heap[child]) return;
		
		swap(heap[parent], heap[child]);
		parent = child;
		child = parent * 2;
	}
}

// 插入元素
void push(int x)
{
	heap[++n] = x;
	up(n);
}

// 删除元素
void pop()
{
	swap(heap[1], heap[n]);
	n--;
	down(1);
}

// 查询堆顶元素
int top()
{
	return heap[1];
}

// 堆的大小
int size()
{
	return n;
}

int main()
{
	int a[10] = { 1, 41, 23, 10, 11, 2, -1, 99, 14, 0 };
	for (int i = 0; i < 10; i++)
	{
		push(a[i]);
	}

	while (size())
	{
		cout << top() << " ";
		pop();
	}
	
	return 0;
}