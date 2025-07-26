//https://ac.nowcoder.com/acm/problem/226303
#include <iostream>

using namespace std;

typedef long long LL;
const int N = 1e5+10;
LL a[N], f[N];

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[i] = a[i] - a[i-1];
	}
	
	while(m--)
	{
		LL l = 0, r = 0, k = 0;
		cin >> l >> r >> k;
		f[l] += k; f[r+1] -= k;
	}
	
	for(int i = 1; i <= n; i++)
	{
		f[i] = f[i-1] + f[i];
		cout <<f[i]<< " ";
	}
	
	return 0;
}