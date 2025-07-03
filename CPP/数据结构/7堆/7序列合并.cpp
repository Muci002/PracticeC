//P1631
#include <iostream>
#include <queue>

using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
LL a[N], b[N];

struct node
{
	LL num;  // 两数和
	int pa;   // a 的下标
	int pb;   // b 的下标
	
	//重载运算符
	bool operator < (const node& x) const
	{
		return num > x.num;
	}
};

priority_queue<node> heap;

int main()
{
	int n = 0; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		heap.push({ a[i] + b[1], i, 1 });
	}

	for (int k = 1; k <= n; k++)
	{
		cout << heap.top().num << " ";
		int i = heap.top().pa, j = heap.top().pb;
		heap.pop();
		if (j + 1 <= n) heap.push({ a[i] + b[j + 1] , i, j + 1 });
	}

	return 0;
}