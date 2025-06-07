#include <iostream>
#include <string>

using namespace std;
typedef unsigned long long LL;
const int N = 1e6+10;

LL stk[N];
int top;

int main()
{
	int t = 0; 
	cin >> t;
	while(t--)
	{
		top = 0;
		int n = 0;
		cin >> n; 
		while(n--)
		{
			string op;
			cin >> op;
			if(op == "push")
			{
				LL x = 0;
				cin >> x;
				stk[++top] = x;
			}
			else if(op == "pop" )
			{
				if(top == 0) cout << "Empty" << endl;
				else top--;
			}
			else if(op == "query")
			{
				if(top == 0) cout << "Anguei!" << endl;
				else cout << stk[top] << endl;
			}
			else if(op == "size")
			{
				cout << top << endl;
			}
		}
	}
	return 0;
}