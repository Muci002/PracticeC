#include <iostream>
#include <stack>

using namespace std;

//size 返回栈的实际的元素个数
//empty 返回栈是否为空
//push 进栈
//pop 出栈
//top 返回栈顶元素

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