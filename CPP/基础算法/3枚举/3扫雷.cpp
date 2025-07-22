// P2327

#include <iostream>

using namespace std;

const int N = 1e4 + 10;
int a[N], b[N];

int main()
{
	int cnt = 0;
	int n = 0; cin >> n;
	for (int i = 1; i <= n; i++) cin >> b[i];

	// 枚举第一个格子有没有放雷
	// 1.有雷
	a[1] = 1;
	bool flag = false;
	for (int i = 1; i <= n; i++)
	{
		a[i + 1] = b[i] - a[i] - a[i - 1];
		if (a[i + 1] != 0 && a[i + 1] != 1)
		{
			flag = true;
			break;
		}
	}
	if (!flag && a[n + 1] == 0) cnt++;
	flag = false;
	// 2.没有雷
	a[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		a[i + 1] = b[i] - a[i] - a[i - 1];
		if (a[i + 1] != 0 && a[i + 1] != 1)
		{
			flag = true;
			break;
		}
	}
	if (!flag && a[n + 1] == 0) cnt++;
	cout << cnt << endl;
	return 0;
}

//·································································
//·································································
//·································································

#include <iostream>

using namespace std;

const int N = 1e4 + 10;
int a[N], b[N], n;

// 枚举第一个格子有没有放雷
	// 1.有雷

int check(int x)
{
	a[1] = x;
	for (int i = 1; i <= n; i++)
	{
		a[i + 1] = b[i] - a[i] - a[i - 1];
		if (a[i + 1] != 0 && a[i + 1] != 1) return 0;
	}
	if (a[n + 1]) return 0;
	return 1;
}

int main()
{
	int cnt = 0;
	 cin >> n;
	for (int i = 1; i <= n; i++) cin >> b[i];

	cnt += check(0);
	cnt += check(1);
	cout << cnt << endl;

	return 0;
}
