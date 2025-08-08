// P1087

#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int n;
string s;

void dfs(int l, int r)
{
	if (l > r) return;
	if (l == r)
	{
		if (s[l] == '1') cout << "I";
		else cout << "B";
			return;
	}
	int mid = (l + r) / 2;
	dfs(l, mid);
	dfs(mid + 1, r);
	bool a = false;
	bool b = false;
	for (int i = l; i <= r;i++)
	{
		if (s[i] == '1') a = true;
		else b = true;
	}
	if (a && b) cout << "F";
	else if (a)cout << "I";
	else cout << "B";
}

int main()
{
	cin >> n;
	n = pow(2, n);
	cin >> s;
	dfs(0, n - 1);
	return 0;
}