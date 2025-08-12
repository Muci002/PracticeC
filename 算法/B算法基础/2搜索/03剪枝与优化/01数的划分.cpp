// P1025

#include <iostream>
#include <vector>
using namespace std;

int n, k;

int path;
vector<int> a;
int cnt;
int dfs(int pos, int begin)
{
	if (pos >= k && path == n)
	{
		return 1;
	}
	if (pos >= k) return 0;
	int ret = 0;
	for (int i = begin; i <= n; i++)
	{
		if (path + (i * (k - pos)) > n) return ret;
		path += i;
		a.push_back(i);
		ret += (dfs(pos + 1, i));
		path -= i;
		a.pop_back();
	}
	return ret;
}

int main()
{
	cin >> n >> k;
	cout << dfs(0, 1);
	return 0;
}