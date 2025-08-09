// P1706

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
int n;
vector<int> path;
unordered_set<int> st;

void dfs()
{
	if (path.size() == n)
	{
		for (auto e : path) printf("%5d", e);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (st.count(i)) continue;
		st.insert(i);
		path.push_back(i);
		dfs();
		int x = path.back();
		path.pop_back();
		st.erase(x);
	}
}

int main()
{
	cin >> n; 
	dfs();
	return 0;
}