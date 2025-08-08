// P1305
#include <iostream>

using namespace std;

const int N = 200;
char l[N], r[N];

void dfs(char ch)
{
	cout << ch ;
	int u = (int)ch;
	if (l[u] != '*') dfs(l[u]);
	if (r[u] != '*') dfs(r[u]);
}

int main()
{
	int n; cin >> n;
	char root; cin >> root;

	int i = (int)root;
	cin >> l[i] >> r[i];

	n--;

	while (n--)
	{
		char ch; cin >> ch;
		
		int i = (int)ch;
		cin >> l[i] >> r[i];

	}
	
	dfs(root);

	return 0;
}