// SP1805

#include <iostream>
#include <stack>

using namespace std;
typedef long long LL;
const int N = 1e6 + 10;
LL a[N], n;
LL x[N], y[N];

int main()
{
	cin >> n;
	{
		for (int i = 1; i <= n; i++) cin >> a[i];

		stack<int> st1;
		for (int i = 1; i <= n; i++)
		{
			while (st1.size() && a[st1.top()] >= a[i]) st1.pop();
			if (st1.size()) x[i] = st1.top();
			else x[i] = 0;
			st1.push(i);
		}

		stack<int> st2;
		for (int i = n; i >= 1; i--)
		{
			while (st2.size() && a[st2.top()] >= a[i]) st2.pop();
			if (st2.size()) y[i] = st2.top();
			else y[i] = n + 1;
			st2.push(i);
		}

		LL ret = 0;
		for (int i = 1; i <= n; i++)
		{
			ret = max(ret, a[i] * (y[i] - x[i] - 1));
		}
		cout << ret << endl;
	}
	
	return 0;
}