//https://ac.nowcoder.com/acm/problem/226333

#include <iostream>

using namespace std;
typedef long long LL;
const int N = 1010;

int arr[N][N];
LL f[N][N];
int n, m, q;

int main()
{
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	//预处理
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			f[i][j] = f[i-1][j] + f[i][j-1] -f[i-1][j-1] + arr[i][j];
		}
	} 
	
	while(q--)
	{
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << f[x2][y2] - f[x1-1][y2] - f[x2][y1-1] + f[x1-1][y1-1] << endl;
	}
	
	
	return 0;
}