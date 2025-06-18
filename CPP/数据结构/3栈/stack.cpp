#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> stk;
	
	for(int i = 1; i <= 10; i++)
	{
		stk.push(i);
	}
	
	while(stk.size())
	{
		cout << stk.top() << endl;
		stk.pop();
	}
	
	return 0;
}