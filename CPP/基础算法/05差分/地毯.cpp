// P3397
#include <iostream>

using namespace std;

const int N = 1010;
int f[N][N], n, m;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		cin >> x1 >> y1 >> x2 >> y2;

		f[x1][y1]++;
		f[x1][y2 + 1]--;
		f[x2 + 1][y1]--;
		f[x2 + 1][y2 + 1]++;

	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
			cout << f[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}