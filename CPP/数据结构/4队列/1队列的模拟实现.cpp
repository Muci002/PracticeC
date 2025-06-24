#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int q[N], h, t;

//入队
void push(int x)
{
	q[++t] = x;
}

//出队
void pop()
{
	h++;
}

//查询队头元素
int front()
{
	return q[h + 1];
}

//查询队尾元素
int back()
{
	return q[t];
}

//判断是否为空
bool empty()
{
	return h == t;
}

//有效元素个数
int size()
{
	return t - h;
}

int main()
{

	return 0;
}