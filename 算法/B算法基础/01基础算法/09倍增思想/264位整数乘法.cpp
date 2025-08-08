// P10446

#include <iostream>

using namespace std;
typedef long long LL;
LL a, b, p;

LL qmul(LL a, LL b, LL p)
{
	LL sum = 0;
	while (b)
	{
		if (b & 1) sum = (sum + a) % p;
		a = (a + a) % p;
		b >>= 1;
	}
	return sum;
}

int main()
{
	cin >> a >> b >> p;
	cout << qmul(a, b, p);
	return 0;
}