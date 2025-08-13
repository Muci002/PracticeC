// P1464

#include <iostream>
#include <cstdio>

using namespace std;
typedef long long LL;
const int N = 25;
LL f[N][N][N];
int w(LL a, LL b, LL c)
{
	
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20)
	{
		//if (f[20][20][20]) return f[20][20][20];
		return f[20][20][20]=w(20, 20, 20);
	}
	if (f[a][b][c])return f[a][b][c];
	if (a < b && b < c) return f[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	return f[a][b][c]=w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main()
{
	LL a = 0, b = 0, c = 0;
	while (cin >> a >> b >> c)
	{
		if (a == -1 && b == -1 && c == -1) break;
		printf("w(%lld, %lld, %lld) = %d\n", a, b, c, w(a, b, c));
	}
	return 0;
}