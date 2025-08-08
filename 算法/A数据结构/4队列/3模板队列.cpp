// 洛谷B3616
#include <iostream>

using namespace std;

const int N = 1e4 + 10;
int q[N], h, t;

int main()
{
	int n = 0, op = 0;
	cin >> n;
	while (n--)
	{
		cin >> op; 
		if (op == 1)
		{
			int x = 0; cin >> x;
			q[++t] = x;
		}
		else if (op == 2)
		{
			if (h == t) cout << "ERR_CANNOT_POP" << endl;
			else h++;
		}
		else if (op == 3)
		{
			if (h == t) cout << "ERR_CANNOT_QUERY" << endl;
			else cout << q[h + 1] << endl;
		}
		else cout << t - h << endl;
	}
	return 0;
}