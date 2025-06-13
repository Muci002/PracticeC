//P1003
#include <iostream>

using namespace std;

const int N = 1e4+10;
int a[N], b[N], g[N], k[N];

int my_find(int x, int y, int n)
{
    //从后往前枚举
	for(int i = n; i >= 1; i--)
	{
		if(x >= a[i] && x <= a[i]+g[i] && y >= b[i] && y <= b[i]+k[i]) return i;
	}
	return -1;
} 

int main()
{
	int n = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i] >> g[i] >> k[i];
	}
	int x = 0, y = 0;
	cin >> x >> y;
	cout << my_find(x, y, n); 
	return 0;
}