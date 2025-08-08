// 洛谷P2085
#include <iostream>
#include <queue>

using namespace std;
const int N = 1e4 + 10;

int a[N], b[N], c[N];
struct node
{
	int k, num, x; // 函数值，函数编号，代入值

	// 重载运算符
	bool operator < (const node& x) const
	{
		return k > x.k;
	}

};

priority_queue<node> heap;

int main()
{
	
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
		heap.push(node{ a[i] + b[i] + c[i], i, 1 });
	}

	while (m--)
	{
		cout << heap.top().k << " ";
		int i = heap.top().num;
		int j = heap.top().x + 1;
		heap.pop();
		int kk = a[i] * (j * j) + b[i] * j + c[i];
		heap.push({ kk, i , j });
	}
	
	return 0;
}