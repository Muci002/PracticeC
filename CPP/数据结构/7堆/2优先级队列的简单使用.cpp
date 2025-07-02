#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> q;  // 默认是一个大根堆

int main()
{
	int a[10] = { 1, 41, 23, 10, 11, 2, -1, 99, 14, 0 };

	for (int i = 0; i < 10; i++)
	{
		q.push(a[i]);
	}

	while (q.size())
	{
		cout << q.top() << " ";
		q.pop();
	}

	return 0;
}