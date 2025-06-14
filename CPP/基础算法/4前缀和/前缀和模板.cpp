//https://ac.nowcoder.com/acm/problem/226282
#include <iostream>

using namespace std;
typedef long long LL;
const int N = 1e5+10;
int arr[N], n, m;
LL f[N];

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	
	//一维前缀和 f[i] = f[i-1] + arr[i]
	for(int i = 1; i <= n; i++)
	{
		f[i] = f[i-1] + arr[i];
	 } 
	 
	while(m--)
	{
		int l = 0, r = 0;
		cin >> l >> r;
		cout << f[r] - f[l-1] << endl;
	}
	
	return 0;
} 