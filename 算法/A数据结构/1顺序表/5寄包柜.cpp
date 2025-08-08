//P3613
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
vector<int> a[N]; //创建 N 个柜子
int n, q;

int main()
{
	cin >> n >> q;
	while (q--)
	{
		int op = 0, i = 0, j = 0, x = 0;
		cin >> op >> i >> j;
		if (op == 1)  //存
		{
			cin >> x;
			if (a[i].size() <= j)
			{
				a[i].resize(j + 1);
			}
			a[i][j] = x;
		}
		else if (op == 2)
		{
			cout << a[i][j] << endl;
		}
	}

	return 0;
}