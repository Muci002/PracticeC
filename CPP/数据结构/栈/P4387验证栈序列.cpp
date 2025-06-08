#include <iostream>
#include <stack>
using namespace std;

const int N = 1e5+10;
int a[N], b[N];

int main()
{
	int Q = 0, n = 0;
	cin >> Q;
	
	while(Q--)
	{
		cin >> n;
		
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) cin >> b[i];
		stack<int> stk;
		int j = 1;
		for(int i = 1; i <= n; i++)
		{
			stk.push(a[i]);
			while(j <= n  && stk.size()&& stk.top() == b[j])
			{
				stk.pop();
				j++;
			}
			
		}
		if(stk.size())
		{
			cout << "No" << endl;
		}
		else cout << "Yes" << endl;
	}
	
	return 0;
}