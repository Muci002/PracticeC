// P10448
// Cnm
#include <iostream>
#include <vector>

using namespace std;
int num;
vector<int> path;
int n, k;

void dfs(int begin)
{
	if (path.size() == k)
	{
		for (auto e : path) cout << e << " ";
		cout << endl;
		return;
	}

	for (int i = begin; i <= n; i++)
	{
		path.push_back(i);
		dfs(i + 1);
		path.pop_back();
	}

}

int main()
{
	cin >> n >> k;
	dfs(1);
	return 0;
}