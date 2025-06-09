#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n = 0; cin >> n;
	for(int i = n; i >= 0; i--)
	{
		int a = 0; cin >> a;
		if(a == 0) continue; //a=0不输出任何东西
		//1.符号 
		else if(a < 0) cout << "-";
		else if(a > 0 && i < n) cout << "+";
		//2.数字 
		int t = abs(a);
		if(t != 1 ||(t == 1 && i == 0)) cout << t;
		
		// 3.次数
		
		if(i > 1) cout << "x^" << i;
		else if ( i == 1)  cout << "x";
		
		
	}
}