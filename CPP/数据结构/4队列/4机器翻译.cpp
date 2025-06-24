//洛谷P1540

#include <iostream>
#include <queue>

using namespace std;

const int N = 1e3 + 10;
bool st[N];
queue<int> q;

int main()
{
	int m = 0, n = 0;
	cin >> m >> n;
	int num = 0; // 计算查询字典的次数
	while (n--)
	{
		int x = 0; cin >> x;
		if (st[x]) continue;
		else 
		{
			q.push(x);
			st[x] = true;
			num++;
			if (q.size() > m)
			{
				st[q.front()] = false;
				q.pop();
			}
		}
	}
	cout << num << endl;
	return 0;
}