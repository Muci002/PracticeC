#include <iostream>
#include <stack>

using namespace std;


int main()
{
	char ch;
	int num = 0;
	stack<int> stk;
	while(1)
	{
		cin >> ch;
		if(ch >= '0' && ch <= '9')
		{
			num = num * 10 + (ch -'0');
		}
		else if(ch == '.')
		{
			stk.push(num);
			num = 0;
		}
		else if(ch == '@')
		{
			break;
		}
		else
		{
			int b = stk.top();
			stk.pop();
			int a = stk.top();
			stk.pop(); 
			if(ch == '+')
			{
				stk.push(a + b);
			}
			else if(ch == '-') stk.push(a - b);
			else if(ch == '*') stk.push(a * b);
			else stk.push(a / b);
		}
	}
	cout << stk.top();
	return 0;
}