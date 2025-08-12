// P1784

#include <iostream>
#include <cstdio>
using namespace std;
const int N = 10;
bool row[N][N];
bool col[N][N];
bool st[N][N][N];
int a[N][N];
int n = 9;

bool found;
void dfs(int x, int y)
{
	if (found) return;
	if (x >= n)
	{
		found = true;
		for (int i = 0; i < n;i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
		return;
	}
	if (y >= n)
	{
		dfs(x + 1, 0);
		return;
	}
	if (a[x][y])
	{
		dfs(x, y + 1);
		return;
	}
	for (int num = 1; num <= 9; num++)
	{
		
		if (row[x][num] || col[y][num] || st[x / 3][y / 3][num]) continue;
		row[x][num] = col[y][num] = st[x / 3][y / 3][num] = true;
		a[x][y] = num;
		dfs(x, y + 1);
		a[x][y] = 0;
		row[x][num] = col[y][num] = st[x / 3][y / 3][num] = false;
	}

}

int main()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
			if (a[i][j])
			{
				row[i][a[i][j]] = col[j][a[i][j]] = st[i / 3][j / 3][a[i][j]] = true;
			}
		}
	}

	dfs(0, 0);

	/*for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}*/
	return 0;
}