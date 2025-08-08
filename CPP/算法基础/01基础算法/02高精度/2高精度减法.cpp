#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N = 1e6 + 0;
string s1, s2;

int a[N], b[N], c[N], la, lb, lc;

void sub(int c[], int a[], int b[])
{
	for (int i = 0; i < lc; i++)
	{
		c[i] += a[i] - b[i];
		if (c[i] < 0)
		{
			c[i] += 10;
			c[i + 1] -= 1;
		}
	}
	while (lc > 1 && !c[lc - 1]) lc--;
}

bool comp()
{
	if (s1.size() != s2.size()) return s1.size() < s2.size();
	return s1 < s2;
}

int main()
{
	cin >> s1 >> s2;
	//判断被减数大于减数的情况
	if (comp())
	{
		swap(s1, s2);
		cout << '-';
	}

	la = s1.size();lb = s2.size();lc = max(la, lb);

	for (int i = 0; i < la; i++) a[la - 1 - i] = s1[i] - '0';
	for (int i = 0; i < lb; i++) b[lb - 1 - i] = s2[i] - '0';

	//高精度减法 c = a - b 
	sub(c, a, b);

	for (int i = lc - 1; i >= 0; i--) cout << c[i];

	return 0;
}
