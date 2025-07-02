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
	while (heap[parent] > 1 && heap[child] > heap[parent])
	{
		swap(heap[parent], heap[child]);
		child = parent;
		parent = child / 2;
	}

}

int main()
{
	
	
	return 0;
}