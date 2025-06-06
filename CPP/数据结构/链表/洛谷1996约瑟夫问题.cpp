#include <iostream>

using namespace std;

const int N = 110;

int ne[N];

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;

	for (int i = 1; i < n; i++) ne[i] = i + 1;
	ne[n] = 1;

	int t = n;

	for (int i = 0; i < n; i++)
	{
		for (int i = 1; i < m; i++)
		{
			t = ne[t];
		}
		cout << ne[t] << " ";
		ne[t] = ne[ne[t]];
	}

	return 0;
}