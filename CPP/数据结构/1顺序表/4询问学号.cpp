// 洛谷P3156
#include <iostream>
#include <vector>

using namespace std;

const int N = 2 * 1e6 + 10;
vector<int> a;
int n, m;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x = 0;
		cin >> x;
		a.push_back(x);
	}

	while (m--)
	{
		int x = 0;
		cin >> x;
		cout << a[x-1] << endl;
	}
	
	return 0;
}