//P1601
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N = 1e6+10;

int a[N], b[N], c[N];
int la, lb, lc;

//高精度加法
void add(int a[], int b[], int c[])
{
	for(int i = 0; i < lc; i++)
	{
		c[i] += a[i] + b[i];
		c[i+1] += c[i] / 10;
		c[i] %= 10;
	}
	if(c[lc]) lc++;
}

int main()
{
	string x, y; cin >> x >> y;
	la = x.size(); lb = y.size(); lc = max(la, lb);
	for(int i = 0; i < la; i++) a[la-1-i] = x[i] - '0';
	for(int i = 0; i < lb; i++) b[lb-1-i] = y[i] - '0';
	
	add(a,b,c);
	for(int i = lc - 1; i >= 0; i--) cout << c[i];
	return 0;
}