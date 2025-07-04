//https://ac.nowcoder.com/acm/problem/226337
#include <iostream>

using namespace std;

typedef long long LL;
const int N = 1010;

LL f[N][N];


void insert(int x1, int y1, int x2, int y2, int k)
{
    f[x1][y1] += k;
	f[x1][y2+1] -= k;
	f[x2+1][y1] -= k;
	f[x2+1][y2+1] += k; 
}

int main()
{
	int n = 0, m = 0, q = 0;
	cin >> n >> m >> q;
	
	//预处理 
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			int x = 0;
			cin >> x;
			insert(i,j, i, j, x);
		}
	}
	
	while(q--)
	{
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0, k = 0;
		cin >> x1 >> y1 >> x2 >> y2 >> k;
		insert(x1, y1, x2, y2, k);
	}
	
	//对差分做前缀和还原数组 
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + f[i][j];
			cout << f[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}