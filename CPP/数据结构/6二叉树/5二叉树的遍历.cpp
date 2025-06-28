// B3642
#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int l[N], r[N];

// 前序遍历
void dfs1(int u)
{
	cout << u << " ";
	if (l[u]) dfs1(l[u]);
	if (r[u]) dfs1(r[u]);
}

// 中序遍历
void dfs2(int u)
{
	if (l[u]) dfs2(l[u]);
	cout << u << " ";
	if (r[u]) dfs2(r[u]);
}

// 后序遍历
void dfs3(int u)
{
	if (l[u]) dfs3(l[u]);
	if (r[u]) dfs3(r[u]);
	cout << u << " ";
}

int main()
{
	int n = 0; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
	}

	dfs1(1);
	cout << endl;

	dfs2(1);
	cout << endl;

	dfs3(1);
	cout << endl;

	return 0;
}