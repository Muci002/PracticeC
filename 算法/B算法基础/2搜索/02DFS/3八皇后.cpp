// P1219

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 15;
int n;
vector<int> path;

vector<vector<int>> a;
bool st1[N*2]; // 标记列是否被使用
bool st2[N* 2]; // 标记主对角线
bool st3[N * 2]; // 标记副对角线

void dfs(int x)
{
	if (x > n)
	{
		a.push_back(path);
		
		return;
	}

	// 枚举列
	for (int y = 1; y <= n; y++)
	{
		if (st1[y]) continue;
		if (st2[y - x + n]) continue;
		if (st3[y + x]) continue;
		st1[y] = true;
		st2[y - x + n] = true;
		st3[y + x] = true;
		path.push_back(y);
		dfs(x + 1);
		st1[y] = false;
		st2[y - x + n] = false;
		st3[y + x] = false;
		path.pop_back();
	}
	return;
}

int main()
{
	cin >> n;
	dfs(1);
	int m = min(3, (int)a.size());
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << a.size();
	return 0;
}