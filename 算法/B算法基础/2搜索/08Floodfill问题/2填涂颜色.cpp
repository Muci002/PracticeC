// P1162

 #include <iostream>

using namespace std;
const int N = 35;
int a[N][N];
int n;
bool st[N][N];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

void dfs(int i, int j)
{
	st[i][j] = true;

	for (int k = 0; k < 8; k++)
	{
		int x = i + dx[k], y = j + dy[k];
		if (x >= 0 && x <= n + 1 && y >= 0 && y <= n + 1 && st[x][y] == false && a[x][y] == 0)
		{
			dfs(x, y);
		}
	}

}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}

	dfs(0, 0);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n;j++)
		{
			if (st[i][j] == false && a[i][j] == 0) cout << 2 << " ";
			else cout << a[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}