//洛谷P1480
#include <iostream>
#include <string>

using namespace std;

const int N = 1e5+10;
typedef long long LL;
int a[N], c[N];
int la, lc;

void sub(int a[], int b, int c[])
{
	LL t = 0;
	for(int i = lc -1; i >= 0; i--)
	{
		//计算当前被除余数 
		t = t*10 + a[i];
	    c[i] = t / b;
		t %= b; 
	}
	while(lc > 1 && c[lc-1] == 0) lc--;
}

int main()
{
	string x;
	int b;
	cin >> x >> b;
	la = x.size();
	lc = la;
	for(int i = 0; i < la; i++) a[la-1-i] = x[i] - '0';
	
	sub(a, b, c);
	
	for(int i = lc-1; i >= 0; i--) cout << c[i];
	 
	return 0;
}