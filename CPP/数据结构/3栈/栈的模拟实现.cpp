#include <iostream>

using namespace std;

const int N = 1e5+10;
 
//创建栈
int stk[N], n;

//进栈
void push(int x)
{
	stk[++n] = x;
} 
 
//出栈
void pop()
{
	n--;
} 

//查询栈顶元素
int top()
{
	return stk[n];
} 

//查询有效元素个数
int size()
{
	return n;
} 

//判断是否为空
bool empty()
{
	return n == 0;
} 

int main()
{
	for(int i = 1; i <= 10; i++)
	{
		push(i);
	}
	
	while(size())
	{
		cout << top() << endl;
		pop();
	}
	return 0;
}