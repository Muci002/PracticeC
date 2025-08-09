// B3623

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int n, k;
vector<int> path;
unordered_set<int> st;
void dfs()
{
	if (path.size() == k)
	{
		for (auto e : path) cout << e << " ";
		cout << endl;
		return;
	}
	for (int i = 1; i <= n;i++)
	{
		if (st.count(i)) continue;
		st.insert(i);
		path.push_back(i);
		dfs();
		int tmp = path.back();
		path.pop_back();
		st.erase(tmp);
	}
}

int main()
{
	cin >> n >> k;
	dfs();
	return 0;
}